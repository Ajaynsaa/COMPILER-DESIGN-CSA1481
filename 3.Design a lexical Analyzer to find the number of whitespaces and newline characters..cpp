#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, whitespaces = 0, newlines = 0;

    printf("Enter a string: ");
    gets(str); // Reads the string

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            whitespaces++;
        if (str[i] == '\n')
            newlines++;
    }

    printf("Number of whitespaces: %d\n", whitespaces);
    printf("Number of newlines: %d\n", newlines);

    return 0;
}
