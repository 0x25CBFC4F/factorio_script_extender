//
// Created by null on 8/11/2022.
//

#ifndef INJECTOR_LOG_EXTENSIONS_H
#define INJECTOR_LOG_EXTENSIONS_H

#include "stdio.h"

_Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL Log(
        _In_z_ _Printf_format_string_ char const* const _Format,
...)
{
    int _Result;
    va_list _ArgList;
    __crt_va_start(_ArgList, _Format);
    char formatBuffer[512];
    sprintf_s(&formatBuffer[0], sizeof(formatBuffer), "%s\n", _Format);
    _Result = _vfprintf_l(stdout, formatBuffer, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Result;
}

#endif //INJECTOR_LOG_EXTENSIONS_H
