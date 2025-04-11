#include <stdio.h>

int main(void) {
    const int matrix[3][5] =
    {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };

    const int* p_arr[3];

    p_arr[0] = matrix[0];
    p_arr[1] = matrix[1];
    p_arr[2] = matrix[2];

    printf("matrix offset : %ld\n", matrix[2] - matrix[0]); /* 이는 행의 간격 을 2번 건너 뛴 10 출력 */
    printf("pointer offset: %ld\n", &p_arr[2] - &p_arr[0]); /* 포인터 변수 끼리의 간격은 4바이트 임을 알 수 있다.. 2 출력 */

    return 0;
}
