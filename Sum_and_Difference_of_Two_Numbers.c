#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    float num_1, num_2;
    scanf("%d%d", &num1, &num2);
    scanf("%f%f", &num_1, &num_2);
    printf("%d %d \n", (num1 + num2), (num1 - num2));
    printf("%.1f %.1f \n", (num_1 + num_2), (num_1 - num_2));
    return 0;
}