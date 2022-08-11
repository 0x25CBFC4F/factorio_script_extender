//
// Created by null on 8/12/2022.
//

#include "resolved_functions.h"

BOOL ResolveFunctions() {
    factorioModule = GetModuleHandle("factorio.exe");

    if(factorioModule == NULL) {
        Log("Failed to get module.");
        return FALSE;
    }

    Log("Got module at %p", factorioModule);

    luaNewStateAddr = (lua_newStateFn) GetProcAddress(factorioModule, "lua_newstate");
    getGlobal = (lua_getglobalFn) GetProcAddress(factorioModule, "lua_getglobal");
    pcallkFn = (lua_pcallkFn) GetProcAddress(factorioModule, "lua_pcallk");
    tobooleanFn = (lua_tobooleanFn) GetProcAddress(factorioModule, "lua_toboolean");
    settopFn = (lua_settopFn) GetProcAddress(factorioModule, "lua_settop");
    pushstringFn = (lua_pushstringFn) GetProcAddress(factorioModule, "lua_pushstring");
    tolstringFn = (luaL_tolstringFn) GetProcAddress(factorioModule, "luaL_tolstring");
    pushcclosureFn = (lua_pushcclosureFn) GetProcAddress(factorioModule, "lua_pushcclosure");
    setglobalFn = (lua_setglobalFn) GetProcAddress(factorioModule, "lua_setglobal");
    loadFilexFn = (luaL_loadfilexFn) GetProcAddress(factorioModule, "luaL_loadfilex");

    Log("lua_newstate = 0x%p", luaNewStateAddr);
    Log("lua_getglobal = 0x%p", getGlobal);
    Log("lua_pcallk = 0x%p", pcallkFn);
    Log("lua_toboolean = 0x%p", tobooleanFn);
    Log("lua_settop = 0x%p", settopFn);
    Log("lua_pushstring = 0x%p", pushstringFn);
    Log("luaL_tolstring = 0x%p", tolstringFn);
    Log("lua_pushcclosure = 0x%p", pushcclosureFn);
    Log("lua_setglobal = 0x%p", setglobalFn);
    Log("luaL_loadfilex = 0x%p", loadFilexFn);

    if(luaNewStateAddr == NULL || getGlobal == NULL || pcallkFn == NULL || tobooleanFn == NULL ||
        settopFn == NULL || pushstringFn == NULL || tolstringFn == NULL || pushcclosureFn == NULL ||
        setglobalFn == NULL) {
        Log("Failed to find some of the required Lua functions :(");
        return FALSE;
    }

    return TRUE;
}