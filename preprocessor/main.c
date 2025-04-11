#include <stdio.h>

#define MONSTER_DATA \
  MONSTER_ENTRY(0, "ant", 100)\
  MONSTER_ENTRY(1, "apple", 150)\
  MONSTER_ENTRY(2, "sudden", 200)\
  MONSTER_ENTRY(3, "boss_ant", 1002)\

int main(void) {

  size_t i;

  int ids[] = {
#define MONSTER_ENTRY(id, name, hp) id,
    MONSTER_DATA
#undef MONSTER_ENTRY
  };

  for (i = 0l; i < sizeof(ids) / sizeof(int); i++ ) {
    printf("%d",ids[i]);
  }

  return 0;
}