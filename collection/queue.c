#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

enum { MAX_NUMS = 8};
int s_nums[MAX_NUMS];
size_t s_front = 0;
size_t s_back = 0;
size_t s_nums_count = 0;

void print_queue() {
    size_t i;

    printf("Queue:");
    for (i = 0; i < s_nums_count; i++) {
        printf(" %d", s_nums[(s_front + i) % MAX_NUMS]);
    }
    printf(" | front: %ld, back: %ld\n", s_front, s_back);
}

bool is_empty() {
    return s_nums_count == 0;
}
void enqueue(int data) {
    assert(s_nums_count < MAX_NUMS);
    s_nums[s_back] = data;
    s_back = (s_back + 1) % MAX_NUMS;
    ++s_nums_count;
}

int dequeue(void) {
    int ret;
    assert(is_empty() == false);
    ret = s_nums[s_front];
    s_front = (s_front + 1) % MAX_NUMS;
    --s_nums_count;
    return ret;
}

int main(void) {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);

    print_queue();
    dequeue();
    print_queue();
    dequeue();
    print_queue();
    dequeue();
    print_queue();
    dequeue();
    print_queue();
    enqueue(5);
    print_queue();
    enqueue(6);
    print_queue();
    enqueue(7);
    print_queue();
    enqueue(8);
    print_queue();


}
