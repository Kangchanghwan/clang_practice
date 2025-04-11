#include "minion.h"
#include <stdio.h>

extern unsigned int g_hp;
extern unsigned int g_power;

int main(void) {

    printf("#before g_hp : %u / g_power : %u\n",g_hp, g_power);
    go_berserker();
    add_gold(10u);
    printf("#before g_hp : %u / g_power : %u\n",g_hp, g_power);

}
