#include <stdio.h>

int main(){
  char string[100];
  printf("Tokenizer Project for Arch1\n\n=========================\n");
  printf("Enter a string to start:\n");
  printf("> ");
  scanf("%[^\n]%*c", string); /* This [^\n] scans until it finds a new line */
  printf("%s\n", string);
}
