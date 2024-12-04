decoder: decoder.o main.o
	gcc decoder.o main.o -o decoder -lm

decoder.o: decoder.c
	gcc -c decoder.c -o decoder.o

main.o: main.c
	gcc -c main.c -o main.o