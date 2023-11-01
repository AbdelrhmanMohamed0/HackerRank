#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// Complete the following function.

int find_nth_term(int n, int a, int b, int c)
{
    // Write your code here.
    int i = 0;
    int array[20] = {a, b, c};
    if (n == 1)
        return a;
    else if (n == 2)
        return b;
    else if (n == 3)
        return c;
    else
    {
        for (i = 3; i < n; i++)
        {
            array[i] = array[i - 1] + array[i - 2] + array[i - 3];
        }
        return array[--i];
    }
}

int main()
{
    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);

    printf("%d", ans);
    return 0;
}
