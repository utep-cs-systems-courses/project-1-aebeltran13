#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if (c == ' ' || c == '\t') return true;
  else return false;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if (c == ' ' || c == '\t') return false;
  else return true;
}
  
/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  while(*str){
    int i = 0;
    if(*str[i] != ' ' || *str[i] != '\t') return *str[i];
    else if(*str[i-1] == ' ' || *str[i] == '\t') return *str[i];
  }
  if(!*str) return 0;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  while(*word){
    
  }
  if(!*word) return 0;
}

/* Counts the number of words in the string argument. */
int count_words(char *str);

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
