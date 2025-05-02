/*

// 1
    1
row ->1
col ->1


// 2
    2 2 2
    2 1 2
    2 2 2
row->3
col->3


// 3
    3 3 3 3 3
    3 2 2 2 3
    3 2 1 2 3
    3 2 2 2 3
    3 3 3 3 3
row->5
col->5


//4
    4 4 4 4 4 4 4
    4 3 3 3 3 3 4
    4 3 2 2 2 3 4
    4 3 2 1 2 3 4
    4 3 2 2 2 3 4
    4 3 3 3 3 3 4
    4 4 4 4 4 4 4
row->7
col->7

*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[1000][1000] = {0};
    int num, temp, col;
    scanf("%d", &num);
    temp = num + (num - 1);
    col = num - 1;
    for (int k = 0; k < num; k++)
    {
        for (int i = 0; i < temp; i++)
        {
            arr[i][col] = arr[col][i] = arr[i][temp - col - 1] = arr[temp - col - 1][i] = num - col;
        }
        col--;
    }
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//another code

/*
#include <stdio.h>

void printPattern(int n) {
    int size = 2 * n - 1;
    
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            int top = i - 1;
            int left = j - 1;
            int bottom = size - i;
            int right = size - j;
            
            // Find the minimum distance from any edge
            int min_distance = top;
            if (left < min_distance) min_distance = left;
            if (bottom < min_distance) min_distance = bottom;
            if (right < min_distance) min_distance = right;
            
            // Calculate the value to print
            int value = n - min_distance;
            printf("%d ", value);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printPattern(n);
    return 0;
}

*/