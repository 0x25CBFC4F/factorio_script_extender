#include "library.h"

BOOL OnAttach() {
    AllocateConsole();

    if(!ResolveFunctions()) {
        Log("Failed to initialize.");
        return FALSE;
    }

    if(!InitializeHooks()) {
        Log("Failed to hook required functions.");
        return FALSE;
    }

    Log("Initialization complete.");

    SetThreadsSuspended(FALSE);

    return TRUE;
}

BOOL OnDetach() {
    DeinitializeHooks();
    Log("Bye-bye!");

    return TRUE;
}

BOOL DllMain(HINSTANCE libraryHandle, DWORD fdwReason, LPVOID lpReserved) {
    if(fdwReason == DLL_PROCESS_ATTACH) {
        return OnAttach();
    }

    if(fdwReason == DLL_PROCESS_DETACH) {
        return OnDetach();
    }

    return TRUE;
}