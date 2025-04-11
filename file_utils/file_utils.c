#include "file_utils.h"
#define LENGTH (1024)

void file_copy_v1(const char* target,const char* dst){

  FILE *target_file;
  FILE *dst_file;
  int c;

  target_file = fopen(target, "rb");

  if(target_file == NULL){
     perror("error while opening target file");
     return;
  }

   dst_file = fopen(dst, "wb");
   if(dst_file == NULL){
     perror("error while creating new file");
     goto close_source;
   }

   c = fgetc(target_file);
   while(c != EOF){
       fputc(c, dst_file);
       c = fgetc(target_file);
   }

close_source:
   if(fclose(target_file) == EOF){
     perror("error while close target file");
   }
}

void print_with_repeats(const char* filename){

  long pos = -1;
  int repeating = 0;
  int c;
  FILE* file;

  file = fopen(filename, "r");
  if(file == NULL) {
    perror("error while open file");
    return;
  }

  c = fgetc(file);
  while(c != EOF){
   if( c != ':'){
     putchar(c);
     goto next_char;
   }
   if(!repeating){
     if(pos < 0) {
       pos = ftell(file);
       if(pos < 0) {
        perror("error while getting start position");
        break;
       }
     } else {
       repeating = 1;
       if(fseek(file, pos, SEEK_SET) != 0){
         perror("error while fseek() to start position");
         break;
        }
     }
     goto next_char;
   }

   repeating = 0;
   pos = -1;
next_char:
   c = fgetc(file);
  }

  if(fclose(file) == EOF) {
    perror("error while closing");
  }
}
