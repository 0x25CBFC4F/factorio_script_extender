#ifndef LUA_HOOK_TEST_LIBRARY_H
#define LUA_HOOK_TEST_LIBRARY_H

#include "main_includes.h"

__declspec( dllexport ) BOOL WINAPI DllMain(HINSTANCE libraryHandle, DWORD fdwReason, LPVOID lpReserved);

BOOL ResolveFunctions();
void SetThreadsSuspended(BOOL suspend);
void AnotherThread();

#endif //LUA_HOOK_TEST_LIBRARY_H
