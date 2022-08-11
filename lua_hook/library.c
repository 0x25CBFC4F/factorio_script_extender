#include "library.h"
#include "typedefs.h"

BOOL DllMain(HINSTANCE libraryHandle, DWORD fdwReason, LPVOID lpReserved) {
    if(fdwReason != DLL_PROCESS_ATTACH) {
        return TRUE;
    }

    AllocateConsole();

    HMODULE factorioModule = GetModuleHandle("factorio.exe");
    lua_newStatePtr luaNewStateAddr = (lua_newStatePtr) GetProcAddress(factorioModule, "lua_newstate");

    Log("Got module at %p", factorioModule);
    Log("Got lua_newstate at %p (GetProcAddress)", luaNewStateAddr);

    setSuspendThreads(FALSE);

    return TRUE;
}

void AllocateConsole() {
    AllocConsole();
    SetConsoleTitle("Factorio Script Extender");
    freopen("CONOUT$", "w", stdout);

    Log("==================================================");
    Log("========      Factorio Script Extender     =======");
    Log("==================================================");
    Log("\n");
}

void setSuspendThreads(BOOL suspend) {
    DWORD currentProcessId = GetCurrentProcessId();
    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    THREADENTRY32 threadEntry;
    threadEntry.dwSize = sizeof(THREADENTRY32);

    Thread32First(hThreadSnapshot, &threadEntry);

    do
    {
        if (threadEntry.th32OwnerProcessID == currentProcessId)
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