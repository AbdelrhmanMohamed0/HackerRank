#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s;
    int x, i = 0;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    x = strlen(s);
    // Write your logic to print the tokens of the sentence here.
    while (x)
    {
        if (s[i] != ' ')
        {
            printf("%c", s[i]);
        }
        else
        {
            printf("\n");
        }
        i++;
        x--;
    }
    return 0;
}
