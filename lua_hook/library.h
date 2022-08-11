#ifndef LUA_HOOK_TEST_LIBRARY_H
#define LUA_HOOK_TEST_LIBRARY_H

#include "Windows.h"
#include "lua.h"
#include <stdio.h>
#include "log_extensions.h"
#include <TlHelp32.h>

__declspec( dllexport ) BOOL WINAPI DllMain(HINSTANCE libraryHandle, DWORD fdwReason, LPVOID lpReserved);

void AllocateConsole();
void setSuspendThreads(BOOL suspend);

#endif //LUA_HOOK_TEST_LIBRARY_H
