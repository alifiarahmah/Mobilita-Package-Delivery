#include <stdio.h>
#include "../modules/gadget.h"
#include "../modules/listpos.h"
// #include <gadgetlist.h> <- buat adt sendiri pakai list statis

/*	BUY: Menampilkan gadget yang dapat dibeli, dan membelinya
	Proses:
	1.	Cek inventory Mobita penuh/tidak pakai isFull().
		Kalo penuh, cabut.
	2.	Iterasi list statis daftar gadget. Tulis dari 1, 2, dst.
		<i+1>. <NamaGadget> (<Harga> Yen) <- hardcode aja?
	3.	Prompt pakai mesin kata (entah dimodif apa engga)
		Kalau 0, kembali. Kalau >= length(list), tidak valid.
	4.	Kalau sudah dibeli, tambah ke inventory gadgetlist
	TODO:
	- Entah gimana di list gadget buat sudah terbeli atau tidak
	- Confirm lagi, masih rada ngawang gadgetnya bebas dibeli berkali2 ato engga
*/
void buy(int money){
	// if(!isFull(Inventory)){
		printf("Uang anda sekarang: %d Yen\n", money);
		printf("Gadget yang tersedia:\n"); // iterasi pake list
		printf("1. Kain Pembungkus Waktu (800 Yen)\n");
		printf("2. Senter Pembesar (1200 Yen)\n");
		printf("3. Pintu Kemana Saja (1500 Yen)\n");
		printf("4. Mesin Waktu (3000 Yen)\n");
		printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
		printf("\nENTER COMMAND: ");
		// mesin kata-in
		
	// } else {
	// 	printf("Inventory anda penuh. Anda tidak bisa membeli gadget baru.\n");
	// }
}