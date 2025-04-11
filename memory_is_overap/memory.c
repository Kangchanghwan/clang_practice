#include "memory.h"

int is_overap(const int* arr1, int arr1_length, const int* arr2, int arr2_length)
{
  return arr1 <= arr2 ?
                      arr1 + arr1_length > arr2 :
                      arr2 + arr2_length > arr1 ;
}
