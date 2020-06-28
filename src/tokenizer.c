#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
/*#include "history.h"*/

/* Return true (non-zero) if c is a whitespace character ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == '\t' || c == ' ' || c == '\0')
    return 1;
  else
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c == '\t' || c == ' ' || c == '\0')
    return 0;
  else
    return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  if(!*str) return 0;
  while(space_char(*str)){
    str++;
  }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  while(non_space_char(*word)){
    word++;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  int num_of_words = 0;
  char prev_char = ' ';
  while(*str){
    if(non_space_char(prev_char) && space_char(*str)){
      num_of_words++;
    }
    prev_char = *str;
    str++;
  }
  
  /*
  char startp;     this holds the pointer to the word start teminator 
  if(!*str) return 0;
  while(*str){
    startp = word_start(str);  Look for start of next word 
    if(word_terminator(startp)){   if it has an end then its word else there are no more words 
      num_of_words++;
      str = word_terminator(startp) + 1;
    }else{
      break;
    }
    } */
  return num_of_words;
}
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *word = malloc(len + 1);
  for(int i = 0; i < len; i++){
    word[i] = inStr[i];
  }
  word[len] = '\0';
  return word;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str){
  int num_words = count_words(str);
  char **tokens = malloc(num_words +1);
  char **point = tokens;
  char *start = str;
  char *end;
  for(int i = 0; i< num_words; i++){
    start = word_start(start);
    end = word_terminator(start);
    int word_len = end - start;
    *point = copy_str(start, word_len);
    point++;
    start = end;
  }
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  while(*tokens){
    printf("%s\n", *tokens);
    tokens++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  int count = 0;
  while(*tokens){
    free(tokens[count]);
    count++;
  }
}

