add-nbo.out: add-nbo.o
	gcc -o add-nbo add-nbo.o

add-nbo.o: add-nbo.c
	gcc -c -o add-nbo.o add-nbo.c

clean:
	rm add-nbo.o add-nbo
