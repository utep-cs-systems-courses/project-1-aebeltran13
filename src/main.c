#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define count_words
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
  scanf("%[^\n]%*c", string); /* This [^\n] scans until it finds a new line */
  printf("%s\n", string);
  
  int num_of_words = count_words(*string);
  printf("%d\n", num_of_words);
  printf("This is a test\n");
  return 0;
}
