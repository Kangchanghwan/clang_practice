#include "vector.h"

void add_vector(const int* vector_1,const int* vector_2, int* out_vector)
{
    unsigned int i;
    for(i = 0 ; i < VECTOR_LENGTH; i++)
    {
    *out_vector++ = *vector_1++ + *vector_2++;
    }
}
