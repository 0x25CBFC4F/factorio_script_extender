//
// Created by null on 8/12/2022.
//

#include "hooked_functions.h"

lua_newStateFn OriginalLuaNewStateFn;

BOOL InitializeHooks() {
    if (MH_Initialize() != MH_OK)
    {
        Log("Failed to initialize MinHook.");
        return FALSE;
    }

    MH_CreateHook(luaNewStateAddr, &NewLuaStateHooked, &OriginalLuaNewStateFn);
    MH_EnableHook(luaNewStateAddr);

    return TRUE;
}

BOOL DeinitializeHooks() {
    MH_DisableHook(luaNewStateAddr);
    MH_RemoveHook(luaNewStateAddr);

    MH_Uninitialize();

    return TRUE;
}

lua_State* NewLuaStateHooked(lua_Alloc f, void *ud) {
    lua_State* newState = (*OriginalLuaNewStateFn)(f, ud);
    PatchLuaState(newState);
    Log("Patched Lua state at 0x%p", newState);
    return newState;
}