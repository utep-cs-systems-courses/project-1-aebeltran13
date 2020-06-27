token_test: main.o tokenizer.o
	cc -o token_test main.o tokenizer.o

clean:
	rm -f *.o token_test

main.o: main.c

tokenizer.o: tokenizer.h tokenizer.c
