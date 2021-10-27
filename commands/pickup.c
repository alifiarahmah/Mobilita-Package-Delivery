#include <stdio.h>
#include "../modules/point.h"
#include "../modules/list_linked.h"
// #include "pesanan.h" <- buatan dari linked list

/*	PICKUP: Mengambil item jika ada pesanan yang harus diambil pada lokasi
	Proses:
	1. 	Iterasi linked list pesanan-yang-harus-dikerjakan,
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
	  Ada 2 kemungkinan:
	  - Modif ADT dari praktikum (not recommended)
	  - Buat ADT baru sesuai fungsi (misal: toDoPesanan, onGoingPesanan)
*/

void pickUp(POINT p, List *toDo, List *onGoing){
}