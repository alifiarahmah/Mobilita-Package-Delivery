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

        printf("Pesanan yang sedang diantarkan: \n");
        while (idx >= 0) {
            ctr++;
            order = ITEM(backpack.buffer[idx]);
            pointDropOff = DROP_OFF(backpack.buffer[idx]);
            printf("%d. ", ctr);
            printItemType(order);
            printf(" (Tujuan: %c)\n", Name(pointDropOff));
            idx++;
        }
    } else {
        printf("Pesanan kosong.\n");
    }
}
