#include <stdio.h>

void print_address(void) {
    int a = 10;
    int* a_address = &a;
    int** a_address_address = &a_address;
    printf("# variable address : %p\n", a_address);
    printf("# variable address of address : %p\n", a_address_address);

    printf("# variable address of address value : %d\n" , **a_address_address);
    printf("# variable address value : %d\n" , *a_address);
}

int main(void) {
    print_address();
    return 0;
}
