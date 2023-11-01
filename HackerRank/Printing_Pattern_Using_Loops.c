#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int c = n + n - 1;
    int matrix[c][c];

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int min_i_j = i < j ? i : j;
            int min_c_i = c - 1 - i < min_i_j ? c - 1 - i : min_i_j;
            int min_c_j = c - 1 - j < min_c_i ? c - 1 - j : min_c_i;
            matrix[i][j] = n - min_c_j;
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
