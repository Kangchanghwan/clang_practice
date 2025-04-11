#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
extern unsigned int g_chequing;
extern unsigned int g_saving;

void deposit_into_chequing(const unsigned int amount);
void deposit_into_saving(const unsigned int amount);
unsigned int get_fee(void);
#endif
