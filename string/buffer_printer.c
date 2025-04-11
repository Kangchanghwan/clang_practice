#include "buffer_printer.h"

static size_t s_buffer_index = 0u;
static char s_buffer[BUFFER_SIZE];

void print_buffer(const char* str){
    size_t str_length = get_string_length(str);
    const char* p = str;

    while( str_length > 0) {
        size_t copy_count = BUFFER_SIZE - s_buffer_index - 1;
        int is_buffer_empty = (s_buffer_index == 0);

        if(str_length < copy_count){
            copy_count = str_length;
        }
        s_buffer_index += copy_count;
        str_length -= copy_count;

        if(is_buffer_empty){
            copy_string_with_count(s_buffer, p, copy_count + 1);
        } else {
            concat_string_with_count(s_buffer, p, copy_count);
        }
        p += copy_count;
        if(s_buffer_index == BUFFER_SIZE - 1){
            printf("%s\n", s_buffer);
            s_buffer_index = 0;
        }
    }
}
