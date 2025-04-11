#include <stdio.h>
#include <string.h>

enum {
    NAME_LEN = 32,
    HUMAN_SIZE = 2
};

typedef struct {
    char firstname[NAME_LEN];
    char lastname[NAME_LEN];
} name_t;

int main(void) {

    name_t out_names[HUMAN_SIZE];
    name_t in_names[HUMAN_SIZE];

    FILE* write_stream;
    FILE* read_stream;
    size_t i;
    const char name_list_file_name[] = "namelist.txt";

    const char human1_firstname[] = "chang hwan";
    const char human1_lastname[] = "kang";
    const char human2_firstname[] = "na yeon";
    const char human2_lastname[] = "kang";

    strncpy(out_names[0].firstname, human1_firstname, NAME_LEN);
    strncpy(out_names[0].lastname, human1_lastname, NAME_LEN);
    strncpy(out_names[1].firstname, human2_firstname, NAME_LEN);
    strncpy(out_names[1].lastname, human2_lastname, NAME_LEN);

    write_stream = fopen(name_list_file_name,"wb");
    if (write_stream == NULL) {
        perror("error while file open");
    }

    fwrite(out_names, sizeof(out_names[0]) ,HUMAN_SIZE, write_stream);
    fflush(write_stream);

    if (fclose(write_stream) == EOF) {
        perror("error while file close");
    }

    read_stream = fopen(name_list_file_name, "rb");
    if (read_stream == NULL) {
        perror("error while file open");
    }

    const size_t read_size = fread(in_names, sizeof(in_names[0]), HUMAN_SIZE, read_stream);
    for (i = 0 ; i < read_size ; i++ ) {
        printf("%s %s \n", in_names[i].firstname, in_names[i].lastname);
    }

    if (fclose(read_stream) == EOF) {
        perror("error while file close");
    }

    return 0;
}
