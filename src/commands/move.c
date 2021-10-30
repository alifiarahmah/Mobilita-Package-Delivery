#include <stdio.h>

#include "../modules/adt.h"

void move(Matrix adjMat, POINT *posNow, int *time) {
    // TODO: Merapikan input
    int ctr, rowIdx;
    char pointName;
    Word input;

    // Adjacency HQ: Elemen ke-0, Adjacency A: elemen ke-1, dst
    ctr = 1;
    rowIdx = Name(*posNow) - 64;

    // HQ
    if (ELMT(adjMat, rowIdx, 0)) {
        printf("%d. HQ (x, y)", ctr);
        ctr++;
    }
    // Iterasi kolom
    for (int j = 1; j < COLS(adjMat); j++) {
        if (ELMT(adjMat, rowIdx, j) == 1) {
            // TODO: Print koordinat bangunan
            printf("%d. %c (x, y)\n", ctr, j + 64);
            ctr++;
        }
    }

    if (Cek)
}