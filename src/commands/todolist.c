#include <stdio.h>
#include "../modules/pesanan.h"

// TODO: periksa lagi format outputnya 

void todolist(Pesanan L, Queue Q){ 
    /*Menampilkan daftar pesanan yang masuk ke to do list */
    printf("Pesanan pada TO Do List:\n");
    int i;
    for (i = 0; i <= IDX_TAIL(Q); i++)
    {
        printf("%d. %c → %c (%c), time: %d\n", i,PICK_UP(L),DROP_OFF(L),ITEM(L),PTIME(L)); 
    }
}