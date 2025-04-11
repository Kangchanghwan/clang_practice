#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INCREMENT (2)
#define LINE_LENGTH (2048)

int main(void) {
    char **lines = NULL;
    char line[LINE_LENGTH];

    size_t max_lines = 0l;
    size_t num_lines = 0l;
    char **tmp = NULL;

    size_t i = 0l;

    while (1) {
        if (!fgets(line, LINE_LENGTH, stdin) || strcmp(line, "exit\n") == 0) {
            clearerr(stdin);
            break;
        }
        if (num_lines == max_lines) {
            tmp = realloc(lines, (max_lines + INCREMENT) * sizeof(char *));
            if (tmp == NULL) {
                fprintf(stderr, "%s\n", "out of mem");
                break;
            }
            lines = tmp;
            max_lines += INCREMENT;
        }
        lines[num_lines] = malloc(strlen(line) + 1);
        if (lines[num_lines] == NULL) {
            fprintf(stderr, "%s\n", "out of mem");
            break;
        }
        strcpy(lines[num_lines++], line);
    }
    for (i = 0 ; i < num_lines; i++) {
        printf("%s", lines[i]);
    }
    for (i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
