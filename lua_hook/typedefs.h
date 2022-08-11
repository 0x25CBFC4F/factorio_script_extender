//
// Created by null on 8/12/2022.
//

#ifndef INJECTOR_TYPEDEFS_H
#define INJECTOR_TYPEDEFS_H

#include "lua.h"

//typedef lua_State *(lua_newstatePtr) (lua_Alloc f, void *ud);
//typedef void (*func_type)(void);
typedef lua_State (*lua_newStatePtr) (lua_Alloc f, void *ud);

#endif //INJECTOR_TYPEDEFS_H
