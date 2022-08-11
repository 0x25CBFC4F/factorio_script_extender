//
// Created by null on 8/12/2022.
//

#ifndef INJECTOR_MAIN_INCLUDES_H
#define INJECTOR_MAIN_INCLUDES_H

// Windows-related
#include "Windows.h"
#include <TlHelp32.h>

// Lua
#include "lua.h"
#include "lauxlib.h"

// Imports
#include <stdio.h>

// MinHook
#include "MinHook.h"

// Internal imports
#include "log_extensions.h"
#include "resolved_functions.h"
#include "console_helpers.h"
#include "thread_helpers.h"
#include "extension_functions.h"
#include "hooked_functions.h"

#endif //INJECTOR_MAIN_INCLUDES_H
