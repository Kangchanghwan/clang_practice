#include <stdio.h>
#include "memory.h"

int main(void)
{
    const int arr1[5] = {1, 2, 3, 5, 6};
    const int arr2[9] = {1, 2, 3, 4 , 8, 9, 11, 22, 44};

    const int* arr3 = arr1 + 3;
    const int arr3_length = 2;

    const int result = is_overap(arr1, ARRAY_LENGTH(arr1), arr2, ARRAY_LENGTH(arr2));
    const int result2 = is_overap(arr1, ARRAY_LENGTH(arr1), arr3, arr3_length);

    printf("result = %d, result = %d",result, result2);
    return 0;
}
