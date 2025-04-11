#include <stdio.h>

#include "shape.h"

int main(void) {
    point_t p0;
    point_t p1;

    line_t line0;
    line_t line1;

    rectangle_t rect;

    p0.x = 5;
    p0.y = 1;

    p1.x = -3;
    p1.y = 6;

    line0.start = p0;
    line0.end = p1;

    line1.start = p1;
    line1.end = p0;

    printf("line0 length^2 : %d\n", get_line_length(line0));
    printf("line1 length^2 : %d\n", get_line_length(line1));

    rect = build_rectangle(p0, p1);

    printf("rect: (%d, %d) (%d, %d)\n", rect.top_left.x, rect.top_left.y, rect.bottom_right.x, rect.bottom_right.y);
    printf("rect area: %d\n", get_rectangle_area(rect));
    return 0;
}
