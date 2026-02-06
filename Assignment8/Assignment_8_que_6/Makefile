so:
	gcc -fPIC -c helper.c -o helper.o
	gcc -shared -o libmath.so helper.o

app:
	gcc -o app main.c -L. -lmath

run:
	LD_LIBRARY_PATH=. ./app

clean:
	rm -f *.o *.so app