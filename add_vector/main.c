#include <stdio.h>
#include "vector.h"

int main(void) {
    int vector_a[VECTOR_LENGTH] = {1, 2, 6};
    int vector_b[VECTOR_LENGTH] = {2, 4, 5};

    int vector_c[VECTOR_LENGTH] = {0,};

    add_vector(vector_a, vector_b, vector_c);

    printf("vector_c : {%d, %d, %d}\n", vector_c[0], vector_c[1], vector_c[2]);

    return 0;
}
