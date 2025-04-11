#include "string_utils.h"


size_t get_string_length(const char* str){
  const char* p = str;
  while(*p) ++p;
  return p - str;
}

int equals(const char* str_1, const char* str_2){
  int result = 0;

  while( *str_1 && *str_1 == *str_2){
    ++str_1;
    ++str_2;
  }

  result = *str_1 - *str_2;

  return result == 0 ? 1 : result;
}

int equals_insensitive(const char* str_1, const char* str_2){
   int result = 0;
   char ch_1;
   char ch_2;

   do{
     ch_1 = tolower(*str_1++);
     ch_2 = tolower(*str_2++);
   }while( *str_1 != '\0' && ch_1 == ch_2);

   result = ch_1 - ch_2;

  return result == 0 ? 1 : result;
}

int tolower(const int ch){
  int local_ch = ch;

  if(local_ch >= 'A' && local_ch <= 'Z'){
    local_ch |= 0x0020;
  }
  return local_ch;
}
int toupper(const int ch){
  int local_ch = ch;

  if(local_ch >= 'a' && local_ch <= 'z'){
    local_ch &= ~0x0020;
  }
  return local_ch;
}

void copy_string(char* out_dest, const char* origin){
  while(*origin != '\0'){
    *out_dest++ = *origin++;
  }
  *out_dest = '\0';
}

void copy_string_with_count(char* out_dest, const char* origin, size_t count){
  int i = count;
  int is_end = 0;

  for(;i > 0; i--){
    if(*origin == '\0'){
      is_end = 1;
    }
    if(is_end == 1){
      *out_dest++ = '\0';
    }else{
      *out_dest++ = *origin++;
    }
  }
}

void concat_string(char* out_dest, const char* origin){
  const char* p = origin;
  out_dest += get_string_length(out_dest);

  while(*p != '\0'){
    *out_dest++ = *p++;
  }

  *out_dest = '\0';
}

void concat_string_with_count(char* out_dest, const char* origin, size_t count){
  int is_end = 0;
  int i = count;
  const char* p = origin;
  out_dest += get_string_length(out_dest);


  for(;i > 0 ; i--){
    if(*p == '\0'){
      is_end = 1;
    }
    if(is_end == 1){
      *out_dest++ = '\0';
    }else{
      *out_dest++ = *p++;
    }
   }

   if(is_end == 0) {
      *out_dest = '\0';
   }
}

void print_memory_str(const char* src,const size_t length){
  size_t i = length;
  for(;i > 0; i--){
    printf("%c /", *src == '\0' ? '0' : *src);
    ++src;
  }
  printf("\n");
}

const char* c_strstr(const char* src, const char* target){

  size_t target_length = get_string_length(target);
  const char* start_p = target;

  while(*src != '\0'){
    if(*src++ == *target){
      target++;
      if(*target == '\0'){
         src -= target_length;
         return src;
      }
    } else {
      target = start_p;
    }
  }
  return NULL;
}

void string_toupper(char* src){
   while(*src != '\0'){
     *src = toupper(*src);
     ++src;
   }
}
void string_tolower(char* src){
  while(*src != '\0'){
    *src = tolower(*src);
    ++src;
  }
}

void hashed_delims(unsigned int is_delim[256] ,char* delims){
  size_t i;
  for (i = 0; delims[i] != '\0'; i++) {
    is_delim[(unsigned char)delims[i]] = 1;
  }
}

char* c_strtok(char* src, char* delims){
  static char* next_p;
  char* start_p;
  unsigned int is_delims[256] = {0,};

  if (src != NULL) next_p = src;
  if (next_p == NULL) return NULL;
  hashed_delims(is_delims, delims);

  while(*next_p != '\0' && is_delims[*next_p % 256]){
    next_p++;
  }
  if(next_p == NULL) return NULL;

  start_p = next_p;
  while(*next_p != '\0' && !is_delims[*next_p % 256]){
    next_p++;
  }

  if (*next_p != '\0') {
    *next_p = '\0';
    next_p++;
  } else {
    next_p = NULL;
  }
  return start_p;
}
