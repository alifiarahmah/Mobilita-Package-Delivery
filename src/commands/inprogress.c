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
        ctr = 1;
        idx = IDX_HEAD(pesanan);

        pointDropOff = DROP_OFF(pesanan.buffer[idx]);
        order = ITEM(pesanan.buffer[idx]);
        while (idx != IDX_TAIL(pesanan)) {
            printf("%d. ", idx+1);
            printItemType(order);
            printf(" (Tujuan: %c)", Name(pointDropOff));
            idx++;
        }
    } else {
        printf("Pesanan kosong.\n");
    }
}
