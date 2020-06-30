token_test: main.o tokenizer.o history.o
	cc -o token_test main.o tokenizer.o history.o

clean:
	rm -f *.o token_test

main.o: main.c

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h history.c
