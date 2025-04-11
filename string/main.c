#include <stdio.h>
#include "string_utils.h"
#include "buffer_printer.h"
#include "file_utils.h"
#include "../memory_is_overap/memory.h"

void test_length_func(void) {
    const char str_length_1[] = "gega";
    const size_t str_length = get_string_length(str_length_1);

    printf("str의 길이: %lu\n", str_length);
    printf("==================\n");
}

void test_equals_func(void) {
    const char* str_equals_1 = "maple";
    const char* str_equals_2 = "story";
    const char* str_equals_3 = "story";
    int result_1 = 0;
    int result_2 = 0;
    result_1 = equals(str_equals_1, str_equals_2);
    result_2 = equals(str_equals_2, str_equals_3);

    printf("str_equals_1(%s) == str_equals_2(%s) 은 %d \n", str_equals_1, str_equals_2, result_1);
    printf("str_equals_2(%s) == str_equals_3(%s) 은 %d \n", str_equals_2, str_equals_3, result_2);
}

void test_equals_insensitive_func(void) {
    const char* str_equals_1 = "maple";
    const char* str_equals_2 = "MAPLE";
    const char* str_equals_3 = "MAPLA";
    int result_1 = 0;
    int result_2 = 0;

    result_1 = equals_insensitive(str_equals_1, str_equals_2);
    result_2 = equals_insensitive(str_equals_1, str_equals_3);

    printf("str_equals_1(%s) == str_equals_2(%s) 은 %d \n", str_equals_1, str_equals_2, result_1);
    printf("str_equals_1(%s) == str_equals_3(%s) 은 %d \n", str_equals_1, str_equals_3, result_2);
}

void test_copy_func(void) {
    const char* str1 = "copyright";
    char copy_str1[11];

    copy_string(copy_str1, str1);

    printf("%s",copy_str1);
}

void test_copy_with_count_func(void) {
    const char* str1 = "copyright";
    char copy_str1[10];

    copy_string_with_count(copy_str1, str1, 10);

    printf("test2 %s\n",copy_str1);
    print_memory_str(copy_str1, 10);
}

void test_concat_string_func(void) {
    const char* str1 = "copyright";
    char str2[15] = "type:";

    concat_string(str2, str1);
    print_memory_str(str2, 15);
}

void test_concat_string_with_count(void) {
    const char* str1 = "copyright";
    char str2[15] = "type:";

    concat_string_with_count(str2, str1, 9);
    print_memory_str(str2, 15);
}

void test_buffer_printer_func(void) {
    const char* str1 = "012345678901234567890123456789";
    print_buffer(str1);
    print_buffer(str1);
    print_buffer(str1);
    print_buffer(str1);
    print_buffer(str1);
    print_buffer(str1);
}

void test_c_strstr_func(void) {
    const char* src = "make smile me ";
    const char* target = "me";

    const char* strstr = c_strstr(src,target);
    if (strstr != NULL) {
        printf("%s\n", strstr);
        print_memory_str(strstr, get_string_length(strstr) + 1);
    }
}

void test_string_upper_lower_func(void) {
    char lowercase[] = "hello my name is changhwan kang!";
    string_toupper(lowercase);

    printf("%s\n", lowercase);
    string_tolower(lowercase);
    printf("%s\n", lowercase);
}

void test_c_strtok_func(void) {
    char str[] = "Hello, world; this:is a test";
    char delims[] = " ,;:";
    char* token =  c_strtok(str, delims);

    while (token != NULL) {
        printf("%s\n", token);
        token = c_strtok(NULL, delims);
    }
}

void test_get_char_func(void) {
    int c;
    c = getchar();

    while (c != EOF) {
        printf("%c" ,c);
        c = getchar();
    }
}

void test_fgets_func(void) {
    char line[10];

    while (fgets(line, 10,stdin) != NULL) {
        printf("%s", line);
    }
}

void test_scanf_func(void) {
    int num;

    scanf("%d", &num);
    printf("%d", num);
}

void test_fgets_with_sscanff_func(void) {
    char line[10];
    int num = 0;
    int sum = 0;
    char str[2];

    while (TRUE) {
        if (fgets(line, 10,stdin) == NULL) {
            clearerr(stdin);
            break;
        }
        if (sscanf(line, "%d 1 %s", &num, str) == 2) {
            sum += num;
            printf("%d\n", sum);
        }
    }
}

int main(void) {

    print_with_repeats("repeat.txt");

    return 0;
}
