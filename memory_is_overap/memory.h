#ifndef MEMORY_H
#define MEMORY_H

#define TRUE (1)
#define FALSE (0)
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int is_overap(const int* arr1, int arr1_length, const int* arr2, int arr2_length);

#endif
