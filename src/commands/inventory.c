#include <stdio.h>
#include "../modules/adt.h"

#ifndef GADGET_UNDEF
#define GADGET_UNDEF '0'
#endif

/* Proses: Menampilkan antarmuka pemakaian gadget */
/* I.S. Banyak gadget dalam inventory tidak melebihi capacity */
/* F.S Jika pemakaian berhasil, gadget yang terpakai menghilang dari inventory */
/*     Jika pemakaian gagal, menuliskan pesan */
void inventory(ListGadget *l) {
    int command, val;
    displayListGadget(*l);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali): ");
    scanf("%d", &command);
    /* Sesuai Command*/
    if (ELMT(*l, command-1) != GADGET_UNDEF) {
        deleteGadget(&l, command-1, &val);
    }
    else {
		printf("Tidak ada Gadget yang dapat digunakan!\n");
	}
}