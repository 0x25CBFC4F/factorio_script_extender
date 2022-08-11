//
// Created by null on 8/11/2022.
//

#ifndef LUA_HOOK_TEST_INJECTOR_MAIN_H
#define LUA_HOOK_TEST_INJECTOR_MAIN_H

#include <stdio.h>
#include <Windows.h>
#include <Tlhelp32.h>

int main();
BOOL runFactorio();
DWORD waitForFactorio();
HANDLE openFactorio(DWORD id);
void setProcessSuspendThreads(DWORD id, BOOL suspend);
void injectLibrary(HANDLE processHandle, const char* libraryPath);
void criticalError();

#endif //LUA_HOOK_TEST_INJECTOR_MAIN_H
