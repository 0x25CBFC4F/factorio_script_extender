cmake_minimum_required(VERSION 3.23)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS -m64)

# Lua Hook Library
project(lua_hook_test C)
add_library(lua_hook_test SHARED lua_hook/library.c lua_hook/log_extensions.h lua_hook/typedefs.h)
target_include_directories(lua_hook_test PRIVATE include/lua-headers-master/csrc/lua-headers)

# Runner & Injector
project(injector C)
add_executable(injector injector/injector_main.c injector/injector_main.h)

