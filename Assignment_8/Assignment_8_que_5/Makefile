helper.o: helper.c helper.h
	gcc -c helper.c

lib: helper.o
	ar rcs libmath.a helper.o

main.o: main.c helper.h
	gcc -c main.c

app: main.o libmath.a
	gcc -o app main.o -L. -lmath

clean:
	rm -f *.o *.a app