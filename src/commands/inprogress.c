#include <stdio.h>
#include "commands.h"

#include "../modules/adt.h"

void inProgress(Stack backpack) {
    int idx;
    int ctr;
    POINT pointDropOff;
    Item order;

    if (!isEmptyStack(backpack)) {
        ctr = 0;
        idx = IDX_TOP(backpack);

        /*printf("Pesanan yang sedang diantarkan: \n");
        while (idx >= 0) {
            ctr++;
            order = ITEM(backpack.buffer[idx]);
            pointDropOff = DROP_OFF(backpack.buffer[idx]);
            printf("%d. ", ctr);
            printItemType(order);
            printf(" (Tujuan: %c)\n", Name(pointDropOff));
            idx++;
        }*/
        
        printf("Pesanan yang sedang diantarkan: \n");
        while(!isEmptyStack(backpack)){
            ctr++;
            pop(&backpack,&pesan);
            if (TYPE(ITEM(pesan)) == 'N'){
                printf("%d. Normal Item (Tujuan: %c)\n",ctr,Name(DROP_OFF(pesan)));
            }
            else if (TYPE(ITEM(pesan)) == 'H'){
                printf("%d. Heavy Item (Tujuan: %c)\n",ctr,Name(DROP_OFF(pesan)));
            }
            else if (TYPE(ITEM(pesan)) == 'P'){
                printf("%d. Perishable Item (Tujuan: %c)\n",ctr,Name(DROP_OFF(pesan)));
            }
            else{
                printf("%d. VIP Item (Tujuan: %c)\n",ctr,Name(DROP_OFF(pesan)));
            }
        }
    } 
    
    else {
        printf("Pesanan kosong.\n");
    }
}
