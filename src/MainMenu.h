#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "boolean.h"
#include "wordmachine.h"

int cekFileAda(char namaFile[]);

void MainMenu(Word *filePath);
/* menampilkan Main Menu, menerima input nama file dari pengguna dan mengembalikannya */