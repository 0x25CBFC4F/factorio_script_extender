//
// Created by null on 8/11/2022.
//

#include "injector_main.h"

int main() {
    BOOL runResult = runFactorio();

    if(!runResult) {
        criticalError();
        return 1;
    }

    DWORD factorioProcessId = waitForFactorio();
    printf("Factorio started at PID: %i\n", factorioProcessId);

    HANDLE factorioHandle = openFactorio(factorioProcessId);

    if(factorioHandle == NULL) {
        criticalError();
        return 1;
    }

    printf("Opened Factorio handle: %p\n", factorioHandle);
    setProcessSuspendThreads(factorioProcessId, TRUE);

    printf("Suspended process.");

    injectLibrary(factorioHandle);

    //setProcessSuspendThreads(factorioProcessId, FALSE);

    printf("Unsuspended process.");

    return 0;
}

BOOL runFactorio() {
    HINSTANCE result = ShellExecute(NULL, NULL, "steam://run/427520", NULL, NULL, SW_SHOWNORMAL);

    if(result <= 32) {
        printf("Failed to start Factorio. Reason: %i\n", result);
        return FALSE;
    }

    printf("Successfully ran Factorio.\n");

    return TRUE;
}

DWORD waitForFactorio() {
    while(1) {
        HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
        PROCESSENTRY32 pEntry;
        pEntry.dwSize = sizeof (pEntry);
        BOOL hRes = Process32First(hSnapShot, &pEntry);
        while (hRes)
        {
            if (strcmp(pEntry.szExeFile, "factorio.exe") == 0)
            {
                CloseHandle(hSnapShot);
                return (DWORD) pEntry.th32ProcessID;
            }
            hRes = Process32Next(hSnapShot, &pEntry);
        }
        CloseHandle(hSnapShot);
    }
}

HANDLE openFactorio(DWORD id) {
    HANDLE prc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, id);

    if(prc == NULL) {
        printf("Failed to acquire handle to Factorio. Error: %i\n", GetLastError());
        return NULL;
    }

    return prc;
}

void setProcessSuspendThreads(DWORD id, BOOL suspend) {
    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    THREADENTRY32 threadEntry;
    threadEntry.dwSize = sizeof(THREADENTRY32);

    Thread32First(hThreadSnapshot, &threadEntry);

    do
    {
        if (threadEntry.th32OwnerProcessID == id)
        {
            HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,threadEntry.th32ThreadID);

            if(suspend) {
                SuspendThread(hThread);
            } else {
                ResumeThread(hThread);
            }

            CloseHandle(hThread);
        }
    } while (Thread32Next(hThreadSnapshot, &threadEntry));

    CloseHandle(hThreadSnapshot);
}

void injectLibrary(HANDLE processHandle) {
    FARPROC loadLibraryAddress = GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
    const char* libraryPath = "C:\\Users\\null\\CLionProjects\\lua-hook-test\\cmake-build-debug\\lua_hook_test.dll";
    LPVOID libraryPathMem = VirtualAllocEx(processHandle, NULL, strlen(libraryPath) + 1, MEM_COMMIT, PAGE_READWRITE);

    size_t bytesWritten = 0;
    WriteProcessMemory(processHandle, libraryPathMem, libraryPath, strlen(libraryPath), &bytesWritten);

    DWORD threadId = 0;
    CreateRemoteThread(processHandle, NULL, NULL, loadLibraryAddress, libraryPathMem, 0, &threadId);
}

void criticalError() {
    printf("Critical error. You may close this window.\n");
    Sleep(-1);
}
