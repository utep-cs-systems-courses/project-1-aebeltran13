#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
/* #include "history.h"*/
#define MAX 64

/* Small set of strings to introduce the program */
void intro(){
  printf("Tokenizer Project for Arch1\n\n=========================\n");
  printf("Enter a string to start:\n");
}

/* MAIN FUNC */
int main(){
  char string[MAX];
  char user_choice; /* Users choice to continue runnin the file */
  char cont = 'y'; /* Continue variable */
  /*
  int id;
  List *list = init_history();
*/
  intro();

  while(cont == 'y'){
    printf("> ");
    scanf("%[^\n]%*c", string); /* %[^\n] will scan until it finds new line*/
    printf("%s\n", string);
    /*    add_history(list, string); */
    char **tokens = tokenize(string);
    print_tokens(tokens);
    /*
    printf("Type 'y' for another sentence, 'h' for history, 'n' to quit\n");
    scanf("%s\n", user_choice);
    if(user_choice == 'y') continue;
    if(user_choice == 'h'){
      print_history(list);
      scanf("Type id: %d\n", id);
      string = get_history(list, id);
      continue;
    }
    if(user_choice == 'n') break;
    */
  }
  
  return 0;
}
