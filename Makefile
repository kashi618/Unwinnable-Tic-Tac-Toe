main: main.c
	gcc -o main.exe main.c

run: main
	./main.exe

clean:
	rm -f main
