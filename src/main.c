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

  printf("  Project 1: TOKENIZER\n++++++++++++++++++++++++\n\n");
  
  while(Power_on != 0){
    if(str_compare(user_choice, "AGN") == 0){ /*AGN Again: Enter a new String*/
      printf("Enter a string(64 characters MAX)\n");
      printf("> ");
      scanf("%[^\n]%*c", string); /* %[^\n] will scan until it finds new line*/
      /*      fgets(string, sizeof(string), stdin);*/
    }
    else if(str_compare(user_choice, "HST") == 0){ /*HST History*/
      /*Printing history and getting previously added string*/
      printf("in History\n");
    }
    else if(str_compare(user_choice, "EOP") == 0){ /*EOP End Of Programm*/
      printf("Thanks, Bye!\n");
      break;
    }else{
      printf("Unknown Command.\n");
      /*Enter user_choice funciton here*/
      printf("Enter Command: \"AGN\" to enter a new string,"
	     "\"HST\" to view history, \"EOP\" to quit.\n");
      scanf("%[^\n]%*c",user_choice);
      printf("\n");
      continue;
    }

    /*After getting a string we tokenize and print tokens. Ask for user_choice*/
    printf("%s\n", string);
    /*tokenize and print tokenz here*/
    
    printf("\nEnter Command: \"AGN\" to enter a new string,"
	    "\"HST\" to view history, \"EOP\" to quit.\n");
    scanf("%[^\n]%*c",user_choice);
    printf("\n");
  }
   
  return 0;
}

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
