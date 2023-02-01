#include <stdio.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

enum TokenType {
  IDENTIFIER,
  NUMBER,
  SYMBOL,
  END
};

char token[MAX_TOKEN_LENGTH];
int tokenLength = 0;

enum TokenType getToken(FILE *fp) {
  int c;
  while ((c = getc(fp)) != EOF) {
    if (isspace(c)) {
      continue;
    }
    if (c == '#') {
      while ((c = getc(fp)) != EOF && c != '\n');
      continue;
    }
    break;
  }
  if (c == EOF) {
    return END;
  }
  if (isdigit(c)) {
    token[tokenLength++] = (char) c;
    while ((c = getc(fp)) != EOF && isdigit(c)) {
      token[tokenLength++] = (char) c;
    }
    ungetc(c, fp);
    return NUMBER;
  }
  if (isalpha(c)) {
    token[tokenLength++] = (char) c;
    while ((c = getc(fp)) != EOF && (isalnum(c) || c == '_')) {
      token[tokenLength++] = (char) c;
    }
    ungetc(c, fp);
    return IDENTIFIER;
  }
  token[tokenLength++] = (char) c;
  return SYMBOL;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: lexer <filename>\n");
    return 1;
  }
  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Error: unable to open file %s\n", argv[1]);
    return 1;
  }
  enum TokenType type;
  while ((type = getToken(fp)) != END) {
    switch (type) {
      case IDENTIFIER:
        printf("IDENTIFIER: %s\n", token);
        break;
      case NUMBER:
        printf("NUMBER: %s\n", token);
        break;
      case SYMBOL:
        printf("SYMBOL: %s\n", token);
        break;
    }
    tokenLength = 0;
  }
  fclose(fp);
  return 0;
}