#include <stdio.h>

#include "color.h"

void print_color(color_t color,const char* name) {
    printf("\t%s:\t0x%08x(%3d, %3d, %3d, %3d)\n",
           name, color.val,
           color.rgba.r, color.rgba.g,
           color.rgba.b, color.rgba.a);
}

int main(void) {

    color_t trans_black;
    color_t red;
    color_t yellow;

    trans_black.val = 0x0;

    red.val = 0;
    red.rgba.r = 0xFF;
    red.rgba.a = 0xFF;

    yellow = red;
    yellow.rgba.g = 0xFF;

    printf("size : %lu\n", sizeof(color_t));

    print_color(trans_black, "black");
    print_color(red, "red");
    print_color(yellow, "yellow");
}
