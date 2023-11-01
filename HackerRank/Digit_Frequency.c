#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *s;
    int x;
    s = malloc(1000 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    x = strlen(s);
    int array1[10] = {0};
    for (int i = 0; i < x; i++)
    {
        switch (s[i])
        {
        case '0':
            array1[0]++;
            break;
        case '1':
            array1[1]++;
            break;
        case '2':
            array1[2]++;
            break;
        case '3':
            array1[3]++;
            break;
        case '4':
            array1[4]++;
            break;
        case '5':
            array1[5]++;
            break;
        case '6':
            array1[6]++;
            break;
        case '7':
            array1[7]++;
            break;
        case '8':
            array1[8]++;
            break;
        case '9':
            array1[9]++;
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array1[i]);
    }
    return 0;
}
