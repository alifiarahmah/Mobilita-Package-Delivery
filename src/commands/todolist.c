#include <stdio.h>
#include "../modules/pesanan.h"
#include "../modules/item.h"

// TODO: periksa lagi format outputnya 

void todolist(Pesanan *L, Queue *Q){ 
    /*Menampilkan daftar pesanan yang masuk ke to do list */
    printf("Pesanan pada TO Do List:\n");
    int i;
    for (i = 0; i <= IDX_TAIL(*Q); i++)
    {
        if (ITEM(*L) == "P"){
            printf("%d. %c → %c (Perishable Item), sisa waktu: %d\n", i,PICK_UP(*L),DROP_OFF(*L),PTIME(*L)); 
        }
        else if (ITEM(*L) == "N"){
            printf("%d. %c → %c (Normal Item)\n", i,PICK_UP(*L),DROP_OFF(*L));
        }
        else if (ITEM(*L) == "H"){
            printf("%d. %c → %c (Heavy Item)\n", i,PICK_UP(*L),DROP_OFF(*L));
        }
        else{
            printf("%d. %c → %c (VIP Item)\n", i,PICK_UP(*L),DROP_OFF(*L));
        }
        
    }
}