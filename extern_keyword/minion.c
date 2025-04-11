unsigned int g_hp = 50u;
unsigned int g_power = 10u;
unsigned int g_gold = 0u;

void go_berserker(void) {
    g_hp += 25;
    g_power += 10;
}
void add_gold(unsigned int gold) {
    g_gold += gold;
}
