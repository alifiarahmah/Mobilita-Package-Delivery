#include <stdio.h>
#include "commands.h"

#include "../modules/adt.h"

void inProgress(Queue pesanan) {
    int idx;
    int ctr;
    POINT pointDropOff;
    Item order;

    printf("Pesanan yang sedang diantarkan: \n");
    if (!isEmpty(pesanan)) {
        ctr = 0;
        idx = IDX_HEAD(pesanan);

        while (idx != IDX_TAIL(pesanan) + 1) {
            ctr++;
            order = ITEM(pesanan.buffer[idx]);
            pointDropOff = DROP_OFF(pesanan.buffer[idx]);
            printf("%d. ", ctr);
            printItemType(order);
            printf(" (Tujuan: %c)\n", Name(pointDropOff));
            idx++;
        }
    } else {
        printf("Pesanan kosong.\n");
    }
}
