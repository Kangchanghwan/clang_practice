#include <stdio.h>
#include <stdarg.h>
#include "my_stdio.h"

static void recusive_print_int(int num){
  if(num == 0){
    return;
  }
  recusive_print_int(num / 10);
  putchar('0' + (num % 10));
}

void print_int(int num){
  if(num == 0){
    putchar('0');
  }
  if(num < 0){
    putchar('-');
    num = -num;
  }
  recusive_print_int(num);
}

void custom_printf(const char* src, ...){
    va_list ap;

    va_start(ap, src);
    {
      while(*src != '\0' ){
         const char* str;
         int decimal;
         if(*src == '%'){
           ++src;
           switch(*src){
             case 'd' :
               decimal = va_arg(ap, int);
             print_int(decimal);
             break;
             case 's' :
               str = va_arg(ap,const char*);
             while(*str){
               putchar(*str);
               ++str;
             }
             break;
             case 'c' :
               putchar(va_arg(ap,int));
             break;
             default :
               putchar('%');
               ++src;
           }
         }else{
           putchar(*src);
         }
         ++src;
      }
    }
    va_end(ap);

}
