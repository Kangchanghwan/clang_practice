#include <limits.h>
#include <stdio.h>
#include <sys/_types/_size_t.h>

#define TRUE (1)
#define FALSE (0)
#define BUCKET_SIZE (23)

int s_numbers[BUCKET_SIZE];

void print_hashtable() {

    size_t i;

    for (i = 0; i < BUCKET_SIZE; i ++) {
        printf("%d \t", s_numbers[i]);
    }
    puts("");

}

void init_hashtable() {
    size_t i;

    for (i = 0; i < BUCKET_SIZE; i++) {
        s_numbers[i] = INT_MIN;
    }
}

int has_value(int value) {
    size_t i;
    int start_index;

    start_index = value % BUCKET_SIZE;
    if (start_index < 0) {
        start_index += BUCKET_SIZE;
    }

    i = start_index;
    do {
        if (s_numbers[i] == value) {
            return TRUE;
        }
        if (s_numbers[i] == INT_MIN) {
            return FALSE;
        }
        i = i + 1 % BUCKET_SIZE;
    } while (i != start_index);
    return FALSE;
}
int add(int value) {

    size_t i;
    int start_index;

    start_index = value % BUCKET_SIZE;
    if (start_index < 0) {
        start_index += BUCKET_SIZE;
    }

    i = start_index;
    do {
        if (s_numbers[i] == INT_MIN || s_numbers[i] == value) {
            s_numbers[i] = value;
            return TRUE;
        }
        i = (i + 1) % BUCKET_SIZE;
    } while (i != start_index);
    return FALSE;
}

int main(void){
    init_hashtable();

    add(10);
    add(132);
    add(1322);

    print_hashtable();

    printf("find 1322 : %d", has_value(1322));
}