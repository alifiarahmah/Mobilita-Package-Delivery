#include <stdio.h>

#include "../modules/adt.h"

void move(Matrix adjMat, POINT *posNow, int *time, ListDin lBuilding) {
    // TODO: Merapikan input
    int ctr, rowIdx, input;
    Word input;
    int posSelected;

    // Adjacency HQ: Elemen ke-0, Adjacency A: elemen ke-1, dst
    ctr = 1;
    rowIdx = Name(*posNow) - 64;

    printf("Posisi yang dapat dicapai: \n");
    // HQ
    if (MAT_ELMT(adjMat, rowIdx, 0) == 1) {
        printf("%d. HQ (x, y)", ctr);
        ctr++;
    }
    // Iterasi kolom
    for (int j = 1; j < COLS(adjMat); j++) {
        if (MAT_ELMT(adjMat, rowIdx, j) == 1) {
            printf("%d. ", ctr);
            displayElmtDin(lBuilding, j);
            printf("\n");
            ctr++;
        }
    }

    // Handler jika input tidak valid
    do {
        printf("Posisi yang dapat dipilih? (Ketik 0 jika ingin kembali)\n");
        printf("ENTER COMMAND: ");
        // TODO: ganti ke mesin kata
        scanf("%d", &input);
        if ((input < 0) || (input > ctr)) {
            printf("Input tidak valid. Ulangi. \n");
        }
    } while ((input < 0) || (input > ctr));

    // Select bangunan
    if (input != 0) {
        ctr = 0;
        posSelected = 0;
        for (int j = 0; j < COLS(adjMat); j++) {
            if (ctr == input) {
                break;
            } else {
                if (ELMT_(adjMat, rowIdx, j) == 1) {
                    ctr++;
                }
                posSelected++;
            }
        }
    }

    *posNow = ELMT_DIN(lBuilding, posSelected);
    *time += 1;
}