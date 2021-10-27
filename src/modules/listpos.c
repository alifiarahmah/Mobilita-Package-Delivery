/*
	NIM							: 13520122
	Nama						: Alifia Rahmah
	Tanggal					: 7 September 2021
	Topik praktikum	: ADT List
	Deskripsi				: File implementasi ADT List implisit listpos.h
*/

/*
	Downloadlah file header listpos.h yang merupakan ADT List dengan representasi implisit, 
	alokasi statik dengan elemen bilangan bulat positif, lalu buatlah file implementasinya.
	Untuk menandai elemen yang tidak terdefinisi dalam list, digunakan nilai -999.
	Kumpulkan file bernama listpos.c
*/

/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
	 positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTPOS_H
#define LISTPOS_H

#include <stdio.h>
#include "boolean.h"
#include "listpos.h"

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType;  /* type elemen List */
typedef struct {
	 ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListPos;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListPos, cara deklarasi dan akses: */
/* Deklarasi : l : ListPos */
/* Maka cara akses: 
	 ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
	 List kosong: semua elemen bernilai VAL_UNDEF
	 Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l){
	/* I.S. l sembarang */
	/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
	/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
	int i;
	for (i = 0; i < CAPACITY; i++){
		ELMT(*l, i) = VAL_UNDEF;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l){
	/* Mengirimkan banyaknya elemen efektif List */
	/* Mengirimkan nol jika List kosong */
	int i = 0;
	while((ELMT(l,i) != VAL_UNDEF) && (i < CAPACITY)){
		i++;
	}
	return i;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i){
	/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
	/* yaitu antara indeks yang terdefinisi utk container*/
	return (i >= 0) && (i < CAPACITY);
}

boolean isIdxEff(ListPos l, int i){
	/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
	/* yaitu antara 0..length(l)-1 */
	return ((i >= 0) && (i < length(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l){
	/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
	return length(l) == 0;
} 

/* *** Test List penuh *** */
boolean isFull(ListPos l){
	/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
	return length(l) == CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l){
	/* I.S. l sembarang */
	/* F.S. List l terdefinisi */
	/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
	/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
	/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
	/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
	/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
						Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
	/*    Jika n = 0; hanya terbentuk List kosong */
	CreateListPos(l);
	int i;
	int n = IDX_UNDEF;
	do {
		scanf("%d", &n);
	} while ((n < 0) || (n > CAPACITY));
	for (i = 0; i < n; i++){
		scanf("%d", &ELMT(*l,i));
	}
}
void displayList(ListPos l){
	/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
		siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
		karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
	/* I.S. l boleh kosong */
	/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika List kosong : menulis [] */
	int i;
	printf("[");
	for(i = 0; i < length(l); i++){
		printf("%d", ELMT(l,i));
		if (i < length(l)-1) {
			printf(",");
		}
	}
	printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
	/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
	/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
				indeks yang sama dijumlahkan */
	/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
				elemen l2 pada indeks yang sama */
	int i;
	ListPos l;
	CreateListPos(&l);
	if (plus){
		for(i = 0; i < length(l1); i++){
			ELMT(l, i) =  ELMT(l1, i) + ELMT(l2, i);
		}
	} else {
		for(i = 0; i < length(l1); i++){
			ELMT(l, i) =  ELMT(l1, i) - ELMT(l2, i);
		}
	}
	return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2){
	/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
		elemennya sama */
	if (length(l1) != length(l2)) return false;
	int i = 0;
	boolean check = (ELMT(l1, i) == ELMT(l2, i));
	while (check && (i < length(l1))){
		if (ELMT(l1, i) != ELMT(l2, i)){
			check = false;
		}
		i++;
	}
	return check;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val){
	/* Search apakah ada elemen List l yang bernilai val */
	/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
	/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
	/* Skema Searching yang digunakan bebas */
	int i;
	for (i = 0; i < length(l); i++){
		if (ELMT(l, i) == val){
			return i;
		}
	}
	return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min){
	/* I.S. List l tidak kosong */
	/* F.S. Max berisi nilai terbesar dalam l;
					Min berisi nilai terkecil dalam l */
	int i;
	*max = ELMT(l, 0); *min = ELMT(l, 0);
	for(i = 1; i < length(l); i++){
		if (ELMT(l, i) > *max){
			*max = ELMT(l, i);
		}
		if (ELMT(l, i) < *min){
			*min = ELMT(l, i);
		}
	}
}

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l){
	/* Menghasilkan true jika semua elemen l genap */
	int i;
	for (i = 0; i < length(l); i++){
		if (ELMT(l, i) % 2 != 0){
			return false;
		}
	}
	return true;
}

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc){
	/* I.S. l boleh kosong */
	/* F.S. Jika asc = true, l terurut membesar */
	/*      Jika asc = false, l terurut mengecil */
	/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
		algoritma bebas */
	int i, j;
	ElType temp;
	if (asc){ // ascending order
		for(i = 0; i < length(*l) - 1; i++){
			for(j = i+1; j < length(*l); j++){
				if (ELMT(*l, i) > ELMT(*l, j)){
					temp = ELMT(*l, i);
					ELMT(*l, i) = ELMT(*l, j);
					ELMT(*l, j) = temp;
				}
			}
		}
	} else { // descending order
		for(i = 0; i < length(*l) - 1; i++){
			for(j = i+1; j < length(*l); j++){
				if (ELMT(*l, i) < ELMT(*l, j)){
					temp = ELMT(*l, i);
					ELMT(*l, i) = ELMT(*l, j);
					ELMT(*l, j) = temp;
				}
			}
		}
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val){
	/* Proses: Menambahkan val sebagai elemen terakhir List */
	/* I.S. List l boleh kosong, tetapi tidak penuh */
	/* F.S. val adalah elemen terakhir l yang baru */
	ELMT(*l, length(*l)) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val){
	/* Proses : Menghapus elemen terakhir List */
	/* I.S. List tidak kosong */
	/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
	/*      Banyaknya elemen List berkurang satu */
	/*      List l mungkin menjadi kosong */
	*val = ELMT(*l,length(*l)-1);
	ELMT(*l, length(*l)-1) = VAL_UNDEF;
}

#endif