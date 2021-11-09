#include <stdio.h>
#include "../modules/listgadget.h"

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
void buy(int money, ListGadget inventory){
	buyGadget(&inventory, money);
}