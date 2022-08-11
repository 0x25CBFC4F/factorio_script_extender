cmake_minimum_required(VERSION 3.23)

set(CMAKE_C_STANDARD 23)
#set(CMAKE_C_FLAGS -m64)

# MinHook
project(minhook C)
add_subdirectory(include/minhook)

# Lua Hook Library
project(lua_hook_test C)
file(GLOB lua_hook_files "lua_hook/*.h" "lua_hook/*.c")
add_library(lua_hook_test SHARED ${lua_hook_files} lua_hook/console_helpers.c lua_hook/console_helpers.h lua_hook/resolved_functions.c lua_hook/main_includes.h lua_hook/thread_helpers.c lua_hook/thread_helpers.h lua_hook/hooked_functions.c lua_hook/hooked_functions.h lua_hook/extension_functions.c lua_hook/extension_functions.h)
target_include_directories(lua_hook_test PRIVATE include/lua)
target_include_directories(lua_hook_test PRIVATE include/minhook/include)
target_link_libraries(lua_hook_test minhook)

# Runner & Injector
project(injector C)
add_executable(injector injector/injector_main.c injector/injector_main.h)
