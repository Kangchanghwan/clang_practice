#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdio.h>
#include <time.h>

void register_error_handler(void (*)(const char* msg));
void log_error(const char* msg);
void default_error_handler(const char* msg);
#endif
