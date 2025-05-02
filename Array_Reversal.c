#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, temp, *arr, i;
    scanf("%d", &num);
    arr = (int *)malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
    {
        scanf("%d", arr + i);
    }

    for (int j = 0; j < num / 2; j++)
    {
        temp = arr[num - j - 1];
        arr[num - j - 1] = arr[j];
        arr[j] = temp;
    }

    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}