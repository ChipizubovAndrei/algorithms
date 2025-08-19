#pragma once

#ifdef WIN32
    #define SORTLIB_EXPORT __declspec(dllexport)
    #define SORTLIB_IMPORT __declspec(dllimport)
#else
    #define SORTLIB_EXPORT
    #define SORTLIB_IMPORT
#endif