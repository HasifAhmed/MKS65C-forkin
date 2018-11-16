all: forkin.o
	gcc forkin.o

run:
	./a.out

clean:
	rm *.o 
	rm a.out

forkin.o:forkin.c
	gcc -c forkin.c
