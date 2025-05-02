#include <stdio.h>

/*

Issues:
The first fgets might capture the leftover newline
from scanf instead of waiting for new user input.

Solution:
To make the code work as expected, you should clear
the input buffer after scanf to ensure that fgets reads
the actual user input.

 */

int main()
{
    char s[100];

    // Read a single character
    scanf("%c", &s[0]);
    printf("%c\n", s[0]);

    // Clear the input buffer
    while (getchar() != '\n')
        ;

    // Read a line of text
    fgets(s, 100, stdin);
    printf("%s", s);

    // Read another line of text
    fgets(s, 100, stdin);
    printf("%s", s);

    return 0;
}
