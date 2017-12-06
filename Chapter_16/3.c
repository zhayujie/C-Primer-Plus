#include <stdio.h>
#include <math.h>

#define DEG_TO_RED ((4 * atan(1)) / 180)

typedef struct polar_v {
    double magnitude;
    double angle;
} Polar_V;

typedef struct rect_v {
    double x;
    double y;
} Rect_V;

Rect_V polar_to_rect(Polar_V pv);

int main(void)
{
    Polar_V input;
    Rect_V result;

    puts("Enter magnitude and angle; enter q to quit:");
    while (scanf("%lf%lf", &input.magnitude, &input.angle) == 2)
    {
        result = polar_to_rect(input);
        printf("x = %.2f, y = %.2f\n", result.x, result.y);
        puts("Next input (q to quit):");
    }
    puts("Bye.");

    return 0;
}

Rect_V polar_to_rect(Polar_V pv)
{
    Rect_V rv;
    rv.x = pv.magnitude * cos(pv.angle * DEG_TO_RED);
    rv.y = pv.magnitude * sin(pv.angle * DEG_TO_RED);

    return rv;
}
