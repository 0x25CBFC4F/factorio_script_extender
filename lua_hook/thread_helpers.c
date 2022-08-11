//
// Created by null on 8/12/2022.
//

#include "thread_helpers.h"

void SetThreadsSuspended(BOOL suspend) {
    DWORD currentProcessId = GetCurrentProcessId();
    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    THREADENTRY32 threadEntry;
    threadEntry.dwSize = sizeof(THREADENTRY32);

    Thread32First(hThreadSnapshot, &threadEntry);

    DWORD currentThread = GetCurrentThreadId();

    do
    {
        if (threadEntry.th32OwnerProcessID == currentProcessId && threadEntry.th32ThreadID != currentThread)
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