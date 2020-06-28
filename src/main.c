#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
/*#include "history.h"*/
#define MAX 64

/* Small set of strings to introduce the program */
void intro(){
  printf("Tokenizer Project for Arch1\n\n=========================\n");
  printf("Enter a string to start:\n");
}

/* MAIN FUNC */
int main(){
  char string[MAX];
  char user_choice = 'y'; /* Users choice to continue runnin the file */
  intro();

  while(user_choice == 'y'){
    printf("> ");
    scanf("%[^\n]%*c", string); /* %[^\n] will scan until it finds new line*/
    printf("%s\n", string);
    char **tokens = tokenize(string);
    print_tokens(tokens);

    printf("Type 'y' for another sentence, 'h' for history, 'n' to quit\n");
    scanf("%s", user_choice);
  }
  
  return 0;
}
