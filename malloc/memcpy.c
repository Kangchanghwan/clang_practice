#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *first_name;
    char *last_name;
} name_t;

int main(void) {
    name_t origin;

    name_t copy_1;

    size_t size = 0;

    origin.first_name = "changhwan";
    origin.last_name = "kang";

    size = strlen(origin.first_name) + 1;
    copy_1.first_name = malloc(size * sizeof(char));
    memcpy(copy_1.first_name, origin.first_name, size);

    size = strlen(origin.last_name) + 1;
    copy_1.last_name = malloc(size * sizeof(char));
    memcpy(copy_1.last_name, origin.last_name, size);


    printf("v copy !! first name : %s  last name : %s \n", copy_1.first_name, copy_1.last_name);

    free(copy_1.first_name);
    free(copy_1.last_name);

    return 0;
}
