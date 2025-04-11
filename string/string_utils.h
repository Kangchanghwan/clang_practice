#ifndef STRING_UTIL_H
#define STRING_UTIL_H
#include <__stddef_size_t.h>
#include <stdio.h>

size_t get_string_length(const char* str);
int equals(const char* str_1, const char* str_2);
int equals_insensitive(const char* str_1, const char* str_2);
int tolower(const int ch);
void copy_string(char* out_dest, const char* origin);
void copy_string_with_count(char* out_dest, const char* origin, size_t count);
void concat_string(char* out_dest, const char* origin);
void concat_string_with_count(char* out_dest, const char* origin, size_t count);
void print_memory_str(const char* src, size_t length);
const char* c_strstr(const char* src, const char* target);
void string_toupper(char* src);
void string_tolower(char* src);
char* c_strtok(char* src, char* delims);

#endif
