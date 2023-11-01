#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, m;
    float c, v;
    scanf("%d %d", &n, &m);
    scanf("%f %f", &c, &v);
    printf("%d %d\n", (n + m), (n - m));
    printf("%0.1f %0.1f\n", (c + v), (c - v));
    return 0;
}
