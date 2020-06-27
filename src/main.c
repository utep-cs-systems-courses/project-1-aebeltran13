#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 64

/* Small set of strings to introduce the program */
void intro(){
  printf("Tokenizer Project for Arch1\n\n=========================\n");
  printf("Enter a string to start:\n");
}

/* MAIN FUNC */
int main(){
  char string[MAX];
  intro();
  printf("> ");
  fgets(string, MAX, stdin);
  printf("%s\n", string);
  char **tokens = tokenize(string);
  print_tokens(tokens);
  return 0;
}
