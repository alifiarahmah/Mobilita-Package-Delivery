#include <stdio.h>
#include "commands.h"

#include "../modules/adt.h"

void inProgress(Queue backpack) {
    int idx;
    int ctr;

    printf("Pesanan yang sedang diantarkan: \n");
    if (!isEmpty(backpack)) {
        ctr = 1;
        idx = IDX_HEAD(backpack);

        while (idx != IDX_TAIL(backpack)) {
            // TODO: Ubah tergantung quality item-nya
            printf("%d. Normal Item (Tujuan: %c)", ctr, Name(DROP_OFF(backpack.buffer[idx])));
            idx++;
        }
    } else {
        printf("Pesanan kosong.");
    }
}
