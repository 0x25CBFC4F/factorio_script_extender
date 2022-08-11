//
// Created by null on 8/12/2022.
//

#ifndef INJECTOR_HOOKED_FUNCTIONS_H
#define INJECTOR_HOOKED_FUNCTIONS_H

#include "main_includes.h"

BOOL InitializeHooks();
BOOL DeinitializeHooks();

lua_State* NewLuaStateHooked(lua_Alloc f, void *ud);

#endif //INJECTOR_HOOKED_FUNCTIONS_H
