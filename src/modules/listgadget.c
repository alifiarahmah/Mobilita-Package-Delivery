/* File: listgadget.h */

/* MODUL PENYIMPANAN GADGET YANG SUDAH DIBELI */
/* modifikasi ADT List Statis */

#ifndef LISTGADGET_H
#define LISTGADGET_H

#include <stdio.h>
#include "boolean.h"
#include "gadget.h"

/*  Kamus Umum */
#define MAXCAP 100
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Gadget ElType;  /* type elemen List */
typedef struct {
	ElType contents[MAXCAP]; /* memori tempat penyimpan elemen (container) */
	int capacity;
} ListGadget;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListGadget, cara deklarasi dan akses: */
/* Deklarasi : l : ListGadget */
/* Maka cara akses: 
	 ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
	 List kosong: semua elemen bernilai VAL_UNDEF
	 Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
/* I.S. l sembarang */
/* F.S. Terbentuk ListGadget l kosong dengan kapasitas 5 */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF, set capacity 5 */
void CreateListGadget(ListGadget *l){
	int i;
	for(i = 0; i < MAXCAP; i++){
		ELMT(*l, i) = VAL_UNDEF;
	}
	CAPACITY(*l) = 5;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
int lengthListGadget(ListGadget l){
	int i = 0;
	while((ELMT(l, i) != VAL_UNDEF) && (i < CAPACITY(l))){
		i++;
	}
	return i;
}

/* ********** Test Indeks yang valid ********** */
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxListGadgetValid(ListGadget l, int i){
	return (i >= 0) && (i <= MAXCAP);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
boolean isIdxListGadgetEff(ListGadget l, int i){
	return (i >= 0) && (i <= CAPACITY(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isEmptyListGadget(ListGadget l){
	return lengthListGadget(l) == 0;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
boolean isFullListGadget(ListGadget l){
	return lengthListGadget(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
	 siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
	 karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
void displayListGadget(ListGadget l){
	// TODO: mungkin command inventory bisa tulis di sini
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
int indexOfListGadget(ListGadget l, ElType val){}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void insertLast(ListGadget *l, ElType val){}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteLast(ListGadget *l, ElType *val){}

/* Proses: Menampilkan antarmuka pembelian gadget */
/* I.S. Mobita berada di Headquarter, banyak gadget dalam inventory tidak melebihi capacity */
/* F.S. Jika pembelian berhasil, gadget yang terbeli masuk ke inventory */
/* 		Jika pembelian gagal, menuliskan pesan */
void buyGadget(ListGadget *l, int money){
	if(!isFullListGadget(*l)){
		printf("Uang anda sekarang: %d Yen\n", money);
		printf("Gadget yang tersedia:\n"); // iterasi pake list
		printf("1. Kain Pembungkus Waktu (800 Yen)\n");
		printf("2. Senter Pembesar (1200 Yen)\n");
		printf("3. Pintu Kemana Saja (1500 Yen)\n");
		printf("4. Mesin Waktu (3000 Yen)\n");
		printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
		printf("\nENTER COMMAND: ");
		// TODO: lengkapin lagi buyGadget
	} else {
		printf("Inventory anda penuh. Anda tidak bisa membeli gadget baru.\n");
	}
}

#endif