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

# Resources

Needed a way to compare string to make the user interface and I found a great
website that explains how strcomp() works in C.

	-[This website is great](https://overiq.com/c-programming-101/the-strcmp-function-in-c/#:~:	text=Syntax%3A%20int%20strcmp%20(const%20char,ASCII%20value%20of%20the%20characters.)
