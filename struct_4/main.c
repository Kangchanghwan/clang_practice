#include <stdio.h>

typedef struct {
  int second;
} sec_t;

void increase_second(sec_t* sec) {
  sec->second++;
}

int main(void) {

  sec_t second;

  increase_second(&second);

  printf("second? %d\n", second.second);

  increase_second(&second);

  printf("second? %d", second.second);

  return 0;
}