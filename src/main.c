#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 64

int main(){
  char string[MAX];
  printf("Tokenizer Project for Arch1\n\n=========================\n");
  printf("Enter a string to start:\n");
  printf("> ");
  scanf("%[^\n]%*c", string); /* This [^\n] scans until it finds a new line */
  printf("%s\n", string);

  int wordCount = count_words(string);
  printf("%d", wordCount);
  
  return 0;
}
