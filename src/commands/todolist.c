#include <stdio.h>
#include "commands.h"

#include "../modules/pesanan.h"
#include "../modules/item.h"

void todolist(Pesanan *L, Queue *Q){ 
    /*Menampilkan daftar pesanan yang masuk ke to do list */
    printf("Pesanan pada TO Do List:\n");
    int i;
    for (i = 0; i <= IDX_TAIL(*Q); i++)
    {
        if (TYPE(ITEM(*L)) == "P"){
            printf("%d. %c → %c (Perishable Item), sisa waktu: %d\n", i,PICK_UP(*L),DROP_OFF(*L),PTIME(*L)); 
        }
        else if (TYPE(ITEM(*L)) == "N"){
            printf("%d. %c → %c (Normal Item)\n", i,PICK_UP(*L),DROP_OFF(*L));
        }
        else if (TYPE(ITEM(*L)) == "H"){
            printf("%d. %c → %c (Heavy Item)\n", i,PICK_UP(*L),DROP_OFF(*L));
        }
        else{
            printf("%d. %c → %c (VIP Item)\n", i,PICK_UP(*L),DROP_OFF(*L));
        }
        
    }
}