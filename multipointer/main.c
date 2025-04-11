#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comparer.h"

enum { WORD_SIZE = 6 };

int main(void) {

    size_t i;
    const char* words[WORD_SIZE] = {"king", "maple", "story", "hover", "google", "simple"};

    puts("\n---sort ascending---");

    qsort(words, WORD_SIZE, sizeof(char*), align_asc );

    for (i = 0; i < WORD_SIZE ; i ++) {
        printf("%s\n", words[i]);
    }

    puts("\n---sort descending---");

    qsort(words, WORD_SIZE, sizeof(char*), align_desc );

    for (i = 0; i < WORD_SIZE ; i ++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
