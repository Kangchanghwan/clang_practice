#include <string.h>
#include "comparer.h"

int align_desc(const void* arg1,const void* arg2){

  const char** w0 = (const char**) arg1;
  const char** w1 = (const char**) arg2;

  return strcmp(*w0, *w1);
}
int align_asc(const void* arg1,const void* arg2){

  const char** w0 = (const char**) arg1;
  const char** w1 = (const char**) arg2;

  return strcmp(*w1, *w0);
}
