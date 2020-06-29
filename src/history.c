#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

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
  while(*new_list != NULL){
    print("%d. %s\n", new_list->id, new_list->str);
    new_list = new_list->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *new_list = list->root;
  Item *temp;
  while(*new_list != NULL){
    temp = new_list->next;
    free(new_list->str);
    free(new_list);
    new_list = temp;
  }
}
