#include <stdio.h>
#include "bank_account.h"



int main(void) {

    printf("# before = g_cheguing : %u g_saving : %u \n", g_chequing, g_saving);

    deposit_into_chequing(500u);
    deposit_into_saving(600u);

    printf("# after = g_cheguing : %u g_saving : %u \n", g_chequing, g_saving);

    printf("# getFee() = %u\n", get_fee());

}
