//
// Created by null on 8/12/2022.
//

#include "extension_functions.h"

static int seLog(lua_State* L) {
    size_t length = 0;
    const char* text = tolstringFn(L, 1, &length);

    Log("%s", text);

    return 1;
}

static int executeBinary(lua_State* L) {
    size_t length = 0;

    const char* filePath = tolstringFn(L, 1, &length);
    int loadResult = loadFilexFn(L, filePath, NULL);
    pcallkFn(L, 0, LUA_MULTRET, 0, 0, NULL);

    if(loadResult != LUA_OK) {
        const char* error = tolstringFn(L, -1, &length);
        Log("LUA error: %s", error);
    }

    Log("Load file result: %i", loadResult);

    return 1;
}

void PatchLuaState(lua_State* state) {
    pushcclosureFn(state, seLog, 0);
    setglobalFn(state, "seLog");

    pushcclosureFn(state, executeBinary, 0);
    setglobalFn(state, "executeBinary");
}
