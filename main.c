#include <stdio.h>
#include <math.h>

int main()
{
   int i,j;
   double tmp;
   double num_arr[3] = {0};
   scanf("%lf %lf %lf", &num_arr[0], &num_arr[1], &num_arr[2]);

   for (i = 0; i < 3 - 1; i++) {
      for (j = i + 1; j < 3; j++) {
         if (num_arr[i] < num_arr[j]) {
            tmp = num_arr[i];
            num_arr[i] = num_arr[j];
            num_arr[j] = tmp;
         }
      }
   }

   printf("%.0f %.0f %.0f", ceil(num_arr[0]), floor(num_arr[2]), round(num_arr[1]));
}
