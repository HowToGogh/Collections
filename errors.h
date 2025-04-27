#pragma once

/*
    The most common errors that can happen during runtime.
    Every error has code that can be equal to function result.
*/
enum error {
    SUCCESS_NO_ERROR     =    1,
    ERROR_MALLOC_FAILURE = -101,
    ERROR_NULL           = -102,
    ERROR_EMPTY_ARRAY    = -103,
    ERROR_FULL_ARRAY     = -104,
    FAILURE_CODE         = -199
};