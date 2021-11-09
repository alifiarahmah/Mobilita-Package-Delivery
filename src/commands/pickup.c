#include <stdio.h>
#include "Map.c"
#include "../modules/pesanan.h"
#include "../modules/pesanan_todo.h"
#include "../modules/tas.h"

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
	  Apalagi tipenya juga bakal beda, pakai ADT Item dan Gadget
*/

void pickUp(POINT posNow, Matrix LokMat, Queue *queuePesanan){
	// lokasi bangunan
	char loc = posisiSkrg(posNow, LokMat);
	// search dari queue, eh, gaboleh langsung cabut dari badannya kan ya queue tuh?
	
}