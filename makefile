CC=gcc -std=c99
TARGET=main.exe

all:
	$(CC) -o $(TARGET) src/main.c src/main_menu.c src/read_file.c src/commands/*.c src/modules/*.c 

clean:
	rm $(TARGET)