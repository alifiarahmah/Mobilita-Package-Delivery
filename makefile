CC=gcc -std=c99
TARGET=main.exe

all:
	$(CC) -o $(TARGET) src/main.c src/commands/Map.c src/main_menu.c src/read_file.c src/modules/wordmachine.c src/modules/charmachine.c src/modules/matrix.c src/modules/item.c src/modules/point.c src/modules/pesanan.c src/modules/pcolor.c -lm

clean:
	rm $(TARGET)