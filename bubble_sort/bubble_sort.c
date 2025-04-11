#include <stdio.h>

void print_array(const int* const num_array, size_t size);
void swap(int* a, int* b);

int main(void) {
    int num_array[6] = {4, 12, 6, 1, 22, 5};
    const size_t size = sizeof(num_array) / sizeof(num_array[0]);
    size_t i;
    size_t j;

    for (i = 0; i < size; i++)
    {
        for (j = 1; j < size - i; j++)
        {
            if (num_array[j - 1] > num_array[j])
            {
                swap(&num_array[j - 1], &num_array[j]);
            }
        }
        printf("==============\n");
        print_array(num_array, size);
    }

    printf("========RESULT======\n");

    print_array(num_array, size);

}

void swap(int* a, int* b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(const int* const num_array, const size_t size) {
    size_t i;

    for (i = 0; i < size; i++) {
        printf("num_array[%zu] : %d\n", i, num_array[i]); /* == printf("num_array[%zu]: %d\n", i, *(num_array + i))*/
    }
}
