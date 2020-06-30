#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/*declaring str_copy function*/
char *str_copy(char *str);

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = 0;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *new_list = malloc(sizeof(Item));
  List *temp = list;
  char *new_str = str_copy(str);
  new_list->id = 1;
  new_list->str = new_str;
  new_list->next = temp->root; /*this pushes the previous item in the list to the end*/
  temp->root = new_list;
  if(temp->root->next != NULL){
    temp->root = temp->root->next;
    while(temp->root != NULL){
      temp->root->id += 1;
      temp->root = temp->root->next;
    }
  }
  temp->root = new_list;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *new_list = list->root;
  while(new_list != NULL){
    if(new_list->id == id){  /* Print item if id matches id that we are looking for */
      return new_list->str;
    }
    new_list->next;
  }
  return 0;
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *new_list = list->root;
  while(new_list != NULL){
    printf("%d. %s\n", new_list->id, new_list->str);
    new_list = new_list->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *new_list = list->root;
  Item *temp;
  while(new_list != NULL){
    temp = new_list->next;
    free(new_list->str);
    free(new_list);
    new_list = temp;
  }
}

/*Copies string ending with \0 to new string*/
char *str_copy(char *str){
  char *end = str;
  while(*end != '\0'){
    end++;
  }
  int len = end-str-1; /*-1 to make up for \0*/
  return copy_str(str,len);
}
