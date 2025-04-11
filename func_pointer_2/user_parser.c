#include "user_parser.h"

#define LINE_LENGTH (1024)


void userdata_parse(userdata_t users[], size_t user_size){

  char* filename = "userdata.txt";
  FILE* stream;
  unsigned int i = 0;
  char line[LINE_LENGTH];


  stream = fopen(filename, "r");

  if(stream == NULL) {
    perror("error while file open");
    return;
  }

  while (fgets(line, LINE_LENGTH, stream) != NULL) {
    printf("Read line: %s", line);

    if (i < user_size) {
      int temp_age;  // ⭐️ int 타입 임시 변수 추가

      int parsed = sscanf(line, "age : %d, id : %d, sex : %d",
                          &temp_age, &users->id, &users->sex);

      if (parsed == 3) {
        users->age = (char) temp_age;  // ⭐️ int → char 변환 후 저장
        printf("Parsed values: age=%d, id=%d, sex=%d (parsed=%d)\n",
               users->age, users->id, users->sex, parsed);
        ++i;
        ++users;
      } else {
        printf("Parsing failed for line: %s\n", line);
      }
    }else{
      break;
    }
  }

}
