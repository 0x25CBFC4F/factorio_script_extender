//
// Created by null on 8/12/2022.
//

#ifndef INJECTOR_RESOLVED_FUNCTIONS_H
#define INJECTOR_RESOLVED_FUNCTIONS_H

#include "main_includes.h"

// int (lua_getglobal) (lua_State *L, const char *name);
// int (lua_pcallk) (lua_State *L, int nargs, int nresults, int errfunc,
//                            lua_KContext ctx, lua_KFunction k); (0, NULL)
// int (lua_toboolean) (lua_State *L, int idx)
// void  (lua_settop) (lua_State *L, int idx);
// const char *(luaL_tolstring) (lua_State *L, int idx, size_t *len);
// void  (lua_pushcclosure) (lua_State *L, lua_CFunction fn, int n);

//LUA_API int             (lua_isnumber) (lua_State *L, int idx);
//LUA_API int             (lua_isstring) (lua_State *L, int idx);
//LUA_API int             (lua_iscfunction) (lua_State *L, int idx);
//LUA_API int             (lua_isinteger) (lua_State *L, int idx);
//LUA_API int             (lua_isuserdata) (lua_State *L, int idx);
//LUA_API int             (lua_type) (lua_State *L, int idx);
//LUA_API const char     *(lua_typename) (lua_State *L, int tp);
// int (luaL_loadfilex) (lua_State *L, const char *filename, const char *mode);

HMODULE factorioModule;

typedef lua_State* (*lua_newStateFn) (lua_Alloc f, void *ud);
typedef int (*lua_getglobalFn) (lua_State *L, const char *name);
typedef int (*lua_pcallkFn) (lua_State *L, int nargs, int nresults, int errfunc, lua_KContext ctx, lua_KFunction k);
typedef int (*lua_tobooleanFn) (lua_State *L, int idx);
typedef void (*lua_settopFn) (lua_State *L, int idx);
typedef const char* (*lua_pushstringFn) (lua_State *L, const char *s);
typedef const char* (*luaL_tolstringFn) (lua_State *L, int idx, size_t *len);
typedef void (*lua_pushcclosureFn) (lua_State *L, lua_CFunction fn, int n);
typedef void (*lua_setglobalFn) (lua_State *L, const char *name);
typedef int (*luaL_loadfilexFn) (lua_State *L, const char *filename, const char *mode);

lua_newStateFn luaNewStateAddr;
lua_getglobalFn getGlobal;
lua_pcallkFn pcallkFn;
lua_tobooleanFn tobooleanFn;
lua_settopFn settopFn;
lua_pushstringFn pushstringFn;
luaL_tolstringFn tolstringFn;
lua_pushcclosureFn pushcclosureFn;
lua_setglobalFn setglobalFn;
luaL_loadfilexFn loadFilexFn;

BOOL ResolveFunctions();

#endif //INJECTOR_RESOLVED_FUNCTIONS_H
