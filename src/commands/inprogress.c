#include <stdio.h>
#include "commands.h"

#include "../modules/adt.h"

void inProgress(LList inprogress) {
    int ctr;
    Pesanan pesan;

    if (!isEmptyLL(inprogress)) {
        ctr = 0;
        LList revInprogress;
        Address p = inprogress;

        CreateList(&revInprogress);
        // Menampilkan dari paling baru, sehingga list harus di reverse
        while (p != NULL) {
            insertFirst(&revInprogress, INFO(p));
            p = NEXT(p);
        }
        
        printf("Pesanan yang sedang diantarkan: \n");
        p = revInprogress;
        while(p != NULL) {
            pesan = INFO(p);
            ctr++;
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
            p = NEXT(p);
        }
    } 
    
    else {
        printf("Pesanan kosong.\n");
    }
}
