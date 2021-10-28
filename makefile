CC=gcc -std=c99
TARGET=main.exe

all:
	$(CC) -o $(TARGET) src/main.c src/modules/wordmachine.c src/modules/charmachine.c

clean:
	rm $(TARGET)