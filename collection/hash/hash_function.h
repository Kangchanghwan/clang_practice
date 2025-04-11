#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H
#include <stddef.h>

size_t hash_int(const int value);
size_t hash_float(const float value);
size_t hash_data(const void* ch, size_t length);
#endif
