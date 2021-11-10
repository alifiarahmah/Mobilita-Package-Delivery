#include <stdio.h>
#include "Map.c"
#include "../modules/adt.h"

/*	PICKUP: Mengambil item jika ada pesanan yang harus diambil pada lokasi
	Proses:
	1. 	Iterasi queue pesanan-yang-harus-dikerjakan,
		cari pesanan pertama dengan pickup di point tsb
		Pakai indexOf()
	2.	Jika ketemu, pesanan dimasukkan ke
		linked list pesanan-yang-sedang-dikerjakan
		- insertLast() pesanan-yang-harus
		- deleteAt() dari pesanan-yang-sedang
		Kontakan lagi buat caritau struct pesanannya kaya gimana
		Jika tidak ketemu, printf("Pesanan tidak ditemukan!\n");
	3.	Setelah dimasukkan, keluarkan pesanan berhasil diambil
		Lalu tulis tujuan
	TODO:
	- Bedakan list statis, dinamis, dan linked list dari ADTnya, soalnya nama-namanya konflik
*/

void pickUp(POINT posNow, Matrix LokMat, Queue *queuePesanan, LList *todo, Stack *tas){
	
	// search dari queue, eh, gaboleh langsung cabut dari badannya kan ya queue tuh?
	// jadi cek dari head aja
	// cek lokasi pick up queue terbaru sama seperti lokasi kita sekarang
	if (EQ(posNow, PICK_UP(HEAD(*queuePesanan)))){
		// ceritanya udah ketemu dulu, dequeque?
		Pesanan thisPesanan;
		dequeue(queuePesanan, &thisPesanan);

		// TODO: kalo ngerjain bonus, taroh juga aturannya di sini
		insertLastLL(todo, thisPesanan); // taroh queue ke inprogress
		// push(tas, ITEM(thisPesanan)); // taroh itemnya ke tas
		push(tas, thisPesanan);

		// output tipe pesanan
		if(TYPE(ITEM(thisPesanan)) == 'N'){
			printf("Pesanan berupa Normal Item berhasil diambil!\n");
		} else if(TYPE(ITEM(thisPesanan)) == 'H'){
			printf("Pesanan berupa Heavy Item berhasil diambil!\n");
		} else if(TYPE(ITEM(thisPesanan)) == 'P'){
			printf("Pesanan berupa Perishable Item berhasil diambil!\n");
		}
		// output tujuan pesanan
		printf("Tujuan Pesanan: %c\n", posisiSkrg(DROP_OFF(thisPesanan)));
	} else {
		printf("Pesanan tidak ditemukan!\n");
	}
}