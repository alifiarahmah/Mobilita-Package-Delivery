#include <stdio.h>
#include "commands.h"

#include "../modules/pesanan.h"
#include "../modules/item.h"

/*void todolist(Queue pesanan){
    /*Menampilkan daftar pesanan yang masuk ke to do list */
    /*printf("Pesanan pada To Do List:\n");
    int i;
    for (i = 0; i <= IDX_TAIL(pesanan); i++)
    {
        if (TYPE(ITEM(pesanan.buffer[i])) == 'P'){
            printf("%d. %c → %c (Perishable Item), sisa waktu: %d\n", i,Name(PICK_UP(pesanan.buffer[i])),Name(DROP_OFF(pesanan.buffer[i])),PTIME(pesanan.buffer[i]));
        }
        else if (TYPE(ITEM(pesanan.buffer[i])) == 'N'){
            printf("%d. %c → %c (Normal Item)\n", i,Name(PICK_UP(pesanan.buffer[i])),Name(DROP_OFF(pesanan.buffer[i])));
        }
        else if (TYPE(ITEM(pesanan.buffer[i])) == 'H'){
            printf("%d. %c → %c (Heavy Item)\n", i,Name(PICK_UP(pesanan.buffer[i])),Name(DROP_OFF(pesanan.buffer[i])));
        }
        else{
            printf("%d. %c → %c (VIP Item)\n", i,Name(PICK_UP(pesanan.buffer[i])),Name(DROP_OFF(pesanan.buffer[i])));
        }

    }
}*/

void todolist(LList toDo){
    printf("Pesanan pada To Do List:\n");
    Address p = toDo;
    int i = 1;
    while(p != NULL){
        if (TYPE(ITEM(INFO(p))) == 'P'){
            printf("%d. %c -> %c (Perishable Item), sisa waktu: %d\n", i,Name(PICK_UP(INFO(p))),Name(DROP_OFF(INFO(p))),(PTIME(INFO(p))-TIME(INFO(p))));
        }
        else if (TYPE(ITEM(INFO(p))) == 'N'){
            printf("%d. %c -> %c (Normal Item)\n", i,Name(PICK_UP(INFO(p))),Name(DROP_OFF(INFO(p))));
        }
        else if (TYPE(ITEM(INFO(p))) == 'H'){
            printf("%d. %c -> %c (Heavy Item)\n", i,Name(PICK_UP(INFO(p))),Name(DROP_OFF(INFO(p))));
        }
        else { // TYPE(ITEM(INFO(p))) == 'V'
            printf("%d. %c -> %c (VIP Item)\n", i,Name(PICK_UP(INFO(p))),Name(DROP_OFF(INFO(p))));
        }
        i++;
        p = NEXT(p);
    }
}
