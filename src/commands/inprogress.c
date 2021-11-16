#include <stdio.h>
#include "commands.h"

#include "../modules/adt.h"

void inProgress(LList pesanan) {
    int idx;
    int ctr;
    POINT pointDropOff;
    Item order;
    Pesanan pesan;

    if (!isEmptyLL(pesanan)) {
        ctr = 0;
        Address p;
        
        printf("Pesanan yang sedang diantarkan: \n");
        while(p != NULL) {
            pesan = INFO(p);
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
