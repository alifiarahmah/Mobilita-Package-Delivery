#include <stdio.h>
#include "commands.h"

#include "../modules/adt.h"

/* Proses: mengambil item jika ada pesanan yang harus diambil pada lokasi. */
/* I.S. posNow, LokMat, todo, inprogress, tas terdefinisi */
/* F.S. Jika ada pesanan pada lokasi dan tas tidak penuh, */
/* 			- Item didelete dari todo */
/* 			- Item di-insertLast ke inprogress */
/* 			- Item dimasukkan ke tas */
/* 			Jika tidak ada pesanan pada lokasi, ditampilkan pesan. */
void pickUp(POINT posNow, Matrix LokMat, LList *todo, LList *inprogress, Stack *tas, int *incTime){
	Pesanan thisPesanan;

	boolean pesananFound = false;
	Address p = *todo;
	while(!pesananFound && (p != NULL)){ // iterasi todo, cari yang posisinya sesuai dengan posNow
		if(EQ(PICK_UP(INFO(p)), posNow)){
			pesananFound = true;
			deleteAt(todo, indexOfLL(*todo, thisPesanan), &thisPesanan); // delete pesanan dari todo
		} else {
			p = NEXT(p);
		}
	}

	if (pesananFound){ // ketemu

		if (IDX_TOP(*tas)+1 > TASCAPACITY(*tas)){ // kalo tasnya tidak penuh
			insertLastLL(inprogress, thisPesanan); // taroh pesanan ke inprogress
			push(tas, thisPesanan); // taroh itemnya ke tas

			// output tipe pesanan
			printf("Pesanan berupa ");
			printItemType(ITEM(thisPesanan));
			printf(" berhasil diambil!\n");
			// output tujuan pesanan
			printf("Tujuan Pesanan: %c\n", posisiSkrg(DROP_OFF(thisPesanan), LokMat));
			if(TYPE(ITEM(thisPesanan)) == 'H'){ // heavyItem
				*incTime++;
			}
		} else {
			printf("Tas anda penuh. Anda tidak dapat menambah pesanan lagi.\n");
		}

	} else {
		printf("Pesanan tidak ditemukan!\n");
	}
}
