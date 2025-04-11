#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "user_sorter.h"
#include "userdata.h"
#include "user_parser.h"

enum { NUM_USERS = 20 };

int main(void) {
    userdata_t users[NUM_USERS];
    size_t i;

    userdata_parse(users, NUM_USERS);

    puts("== sort by age, id==\n");

    qsort(users, NUM_USERS, sizeof(users[0]) , compare_age_id);

    for (i = 0; i < NUM_USERS; ++i) {
        printf("age : %3d, id : %3d, sex: %d\n"
            ,users[i].age, users[i].id, users[i].sex);
    }

    puts("\n=== sort by age(desc) sex===");

    qsort(users, NUM_USERS, sizeof(users[0]) , compare_age_desc_sex);

    for (i = 0; i < NUM_USERS; ++i) {
        printf("age : %3d, id : %3d, sex: %d\n"
            ,users[i].age, users[i].id, users[i].sex);
    }

    printf("users[0] size? %lu",sizeof(users[0]));

    return 0;
}
