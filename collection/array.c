#include <assert.h>
#include <stdio.h>

enum {MAX_NUMS = 8};
enum {INVALID_INDEX = -1};

int s_nums[MAX_NUMS];
size_t s_num_count;


void print_arr() {
    size_t i;
    for (i = 0; i < MAX_NUMS ; i++) {
        printf("%d " , s_nums[i]);
    }
    printf("\n");

}

int index_of(const int data) {
    size_t i;

    for (i = 0; i < s_num_count ; i ++) {
        if (s_nums[i] == data) {
            return i;
        }
    }

    return INVALID_INDEX;
}

void delete_at(int index) {
    size_t i;

    assert(index < s_num_count);

    s_num_count--;
    for (i = index; i < s_num_count; i ++) {
        s_nums[i] = s_nums[i + 1];
    }
}

void delete_at_unordered(int index) {
    assert(index < s_num_count);
    s_nums[index] = s_nums[--s_num_count];
}

void insert_at(int index, int data) {
    size_t i = 0;

    assert(index <= MAX_NUMS);
    assert(s_num_count < MAX_NUMS);

    for ( i = s_num_count ; i > index ; i--) {
        s_nums[i] = s_nums[i - 1];
    }

    s_nums[index] = data;
    ++s_num_count;
}

int main(void){

    insert_at(0, 1);
    insert_at(0, 2);
    insert_at(0, 3);
    insert_at(0, 4);
    insert_at(0, 5);
    insert_at(0, 6);
    insert_at(6, 7);
    insert_at(7, 8);
    print_arr();

    delete_at(0);
    print_arr();

    delete_at(5);
    print_arr();

    printf("%d\n", index_of(5));
    delete_at(index_of(5));
    print_arr();
    printf("%d\n", index_of(5));

    delete_at_unordered(2);
    print_arr();
}

