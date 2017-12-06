#include <stdio.h>
int set_mode(int mode);
void show_info(double * distance, double * fuel, int mode);

int set_mode(int mode)
{
    int last_mode = 0;
    if (mode != 0 && mode != 1)
    {
        printf("Invalid mode specified. Mode %s used.\n",
                last_mode == 0 ? "0 (metric)" : "1 (US)");
    }
    else
        last_mode = mode;

    return last_mode;
}

void get_info(int mode)
{
    double * p1, * p2;
    double distance, fuel;

    printf("Enter distance traveled in %s: ",
            set_mode(mode) == 0 ? "kilometers" : "miles");
    scanf("%lf", &distance);
    printf("Enter fuel consumed in %s: ",
            set_mode(mode) == 0 ? "liters" : "gallons");
    scanf("%lf", &fuel);
    p1 = &distance;
    p2 = &fuel;
    show_info(p1, p2, mode);
}

void show_info(double * distance, double * fuel, int mode)
{
    printf("Fuel consumption is ");
    if (set_mode(mode) == 0)
        printf("%.2f liters per 100 km.\n", *fuel / *distance * 100);
    else
        printf("%.1f miles per gallon.\n", *distance / *fuel);
}
