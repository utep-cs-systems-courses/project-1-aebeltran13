#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 64

/*Declaring str_compare*/
int str_compare(char *str1, char *str2);

/* MAIN FUNC */
int main(){
  char string[MAX];
  char user_choice[] = "AGN"; /* Users choice to continue running the file */
  int Power_on = 1;
  List *history_list = init_history();
  char **tokens;
  printf("  Project 1: TOKENIZER\n++++++++++++++++++++++++\n\n");
  
  while(Power_on != 0){
    if(str_compare(user_choice, "AGN") == 0){ /*AGN Again: Enter a new String*/
      
      printf("Enter a string(64 characters MAX)\n");
      printf("> ");
      scanf("%[^\n]%*c", string); /* %[^\n] will scan until it finds new line*/
      
      /*After getting a string we tokenize*/
      printf("%s\n", string);
      /*tokenize and print tokens here*/
      tokens = tokenize(string);
      add_history(history_list, string);
    }
    else if(str_compare(user_choice, "HST") == 0){ /*HST History*/

      /*Printing history and getting previously added string*/
      int id_choice;
      printf("++ History ++ \n");
      print_history(history_list);
      printf("Which one would you like to re-use?\n!");
      scanf("%d%*c",&id_choice);            /*%*c reads the character after and discards it*/
      printf("%d\n", id_choice);
      char *hist_string = get_history(history_list, id_choice);

      /*After getting a string we tokenize*/
      printf("%s\n", hist_string);
      tokens = tokenize(hist_string);
      add_history(history_list, hist_string);
    }
    else if(str_compare(user_choice, "EOP") == 0){ /*EOP End Of Programm*/
      printf("Thanks, Bye!\n");
      break;
    }else{                                        /*UNKNOWN COMMAND*/

      printf("Unknown Command.\n");
      /*Enter user_choice funciton here*/
      printf("\nEnter Command: \"AGN\" to enter a new string,"
	    "\"HST\" to view history, \"EOP\" to quit.\n");
      scanf("%[^\n]%*c",user_choice);
      printf("\n");
      continue;
    }

    print_tokens(tokens);
    free_tokens(tokens);

    /*Command menu to choose what to do next*/
    printf("\nEnter Command: \"AGN\" to enter a new string,"
	    "\"HST\" to view history, \"EOP\" to quit.\n");
    scanf("%[^\n]%*c",user_choice);
    printf("\n");
  }
  free_history(history_list);
  return 0;
}

/*Function that compares to strings and returns 0 if equal*/
int str_compare(char *str1, char *str2){
  while((*str1 != '\0' && *str2 != '\0') && *str1 == *str2){
    str1++;
    str2++;
  }
  if(*str1 == *str2){
    return 0;
  }
  else{
    return *str1 - *str2;
  }
}
