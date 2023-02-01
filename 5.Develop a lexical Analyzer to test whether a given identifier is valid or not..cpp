#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char identifier[100];
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    int len = strlen(identifier);
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        printf("Invalid identifier: first character must be a letter or underscore.\n");
        return 0;
    }

    for (int i = 1; i < len; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            printf("Invalid identifier: character must be a letter, digit, or underscore.\n");
            return 0;
        }
    }

    printf("Valid identifier.\n");
    return 0;
}
