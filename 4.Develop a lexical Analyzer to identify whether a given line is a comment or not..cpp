#include <stdio.h>

int main() {
    char line[100];
    printf("Enter a line of code: ");
    gets(line);

    if (line[0] == '/' && line[1] == '/')
        printf("This is a comment.\n");
    else if (line[0] == '/' && line[1] == '*')
        printf("This is a comment.\n");
    else
        printf("This is not a comment.\n");

    return 0;
}
