#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

enum TokenType {
  IDENTIFIER,
  CONSTANT,
  OPERATOR
};

char input[MAX_LENGTH];
int index = 0;

enum TokenType getNextToken() {
  while (isspace(input[index])) {
    index++;
  }
  if (isalpha(input[index])) {
    return IDENTIFIER;
  } else if (isdigit(input[index])) {
    return CONSTANT;
  } else {
    return OPERATOR;
  }
}

int main() {
  printf("Enter an expression: ");
  fgets(input, MAX_LENGTH, stdin);

  while (input[index] != '\0') {
    enum TokenType type = getNextToken();
    switch (type) {
      case IDENTIFIER:
        printf("IDENTIFIER\n");
        break;
      case CONSTANT:
        printf("CONSTANT\n");
        break;
      case OPERATOR:
        printf("OPERATOR\n");
        break;
    }
    index++;
  }

  return 0;
}
