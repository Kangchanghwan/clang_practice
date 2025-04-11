#include <stdio.h>
#include "hash_function.h"
#include <string.h>

typedef struct {
  unsigned char age;
  unsigned int id;
  char name[64];
} employee_t;

int main(void){
   employee_t person;
   size_t hash;
   float fvalue;

   hash = hash_int(10);
   printf("hashint => %ld\n", hash );
   hash = hash_int(-10);
   printf("hashint => %ld\n", hash );
   hash = hash_int('A');
   printf("hashint => %ld\n", hash );

   hash = hash_float(3.2f);
   printf("hashfloat => %ld\n", hash );

   hash = hash_data("kang", strlen("kang"));
   printf("hashdata(string) => %ld\n", hash );

   fvalue = 3.2f;
   hash = hash_data(&fvalue, sizeof(fvalue));
    printf("hashdata(float) => %ld\n", hash );


   memset(&person , 0, sizeof(employee_t));
   person.age = 10;
   person.id = 10332;
   strcpy(person.name, "KangChangHwan");

   hash = hash_data(&person, sizeof(employee_t));
   printf("hashdata(struct) => %ld\n", hash );

   return 0;
}
