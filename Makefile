main: main.c
	gcc main.c ui.c -o tictactoe.exe

run: main
	./tictactoe.exe

clean:
	rm -f tictactoe.exe
