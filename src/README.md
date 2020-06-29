Project 1: Tokenizer
====================
# Instructions:

To run the program simply type *make* and it creates a file names token_test.
Run token_test(./token_test) in order to start the tokenizer.

# Known Bugs

-After tokenizing sentence, if there is no space at the end it does not read
 the last word.(FIXED)
-When printing tokens, error message "Segmentation fault (core dumped)"
 appears. This is because print_tokens is trying to access information that is
 not there.
-history.c has many warnings due to pointer assignment issues.
