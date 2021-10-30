CC=gcc -std=c99
TARGET=main.exe

all:
	$(CC) -o $(TARGET) src/main.c -lm

clean:
	rm $(TARGET)