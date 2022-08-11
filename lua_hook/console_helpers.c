//
// Created by null on 8/12/2022.
//

#include "Windows.h"
#include <stdio.h>
#include "console_helpers.h"

void AllocateConsole() {
    AllocConsole();
    SetConsoleTitle("Factorio Script Extender");
    freopen("CONOUT$", "w", stdout);

    printf("==================================================\n");
    printf("========      Factorio Script Extender     =======\n");
    printf("==================================================\n\n");
}