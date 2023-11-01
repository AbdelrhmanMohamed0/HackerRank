#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000
int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, sum = 0;
    scanf("%d", &n);
    int array1[MAX];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array1[i]);
        sum += array1[i];
    }
    printf("%d", sum);
    return 0;
}
