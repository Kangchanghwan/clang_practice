#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

enum { MAX_NUMS = 8 };
enum { INVALID_INDEX = -1};

int s_nums[MAX_NUMS];
size_t head = 0;

void print_stack() {
    size_t i = 0;
    for (i = 0; i < head; i++ ) {
        printf("%d ", s_nums[i]);
    }
    puts("");
}


int is_empty() {
    return head == 0;
}

void push(int data) {
    assert(head < MAX_NUMS);
    s_nums[head++] = data;
}

int pop() {
    assert(is_empty() == false);
    return s_nums[--head];
}

int index_of(int data) {
    size_t i = 0;
    int tmp_arr[head];
    int tmp;
    size_t result = 0;
    while (is_empty()  == false) {
        tmp = pop();
        tmp_arr[i++] = tmp;
        if (tmp == data) {
            result = head;
            for (; i > 0 ; i --) push(tmp_arr[i - 1]);
            return result;
        }
    }
    return INVALID_INDEX;
}



int main(void){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    print_stack();

    printf("pop() = %d \n",pop());
    print_stack();
    printf("index_of() = %d\n" ,index_of(2));
    print_stack();

}