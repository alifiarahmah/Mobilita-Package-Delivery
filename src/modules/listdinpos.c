/*
	NIM : 13520122
	Nama : Alifia Rahmah
	Tanggal : 16/09/2021
	Topik praktikum : ADT List Dinamis
	Deskripsi : Praktikum 4 - listdinpos.c
*/

/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
	 memori list dinamik */

#ifndef LISTDINPOS_H
#define LISTDINPOS_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/*  Kamus Umum */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef int ElType;  /* type elemen list */
typedef struct
{
	ElType *buffer; /* memori tempat penyimpan elemen (container) */
	int capacity;  /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
	 l.buffer    untuk mengakses seluruh nilai elemen list
	 l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
	List kosong: semua elemen bernilai VAL_UNDEF
	Definisi elemen pertama : l.buffer[i] dengan i=0
	Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i terbesar
																						 sehingga l.buffer[i] != VAL_UNDEF
	Definisi nEff: jumlah elemen efektif, di mana l.buffer[nEff] == VAL_UNDEF
																						 dan l.buffer[nEff-1] != VAL_UNDEF */

/* ********** SELEKTOR ********** */
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */
void CreateListDin(ListDin *l, int capacity){
	 CAPACITY(*l) = capacity;
	BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
	 int i;
	 for(i = 0; i < CAPACITY(*l); i++){
			ELMT(*l, i) = VAL_UNDEF;
	 }
}

/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */
void dealocate(ListDin *l){
	 CAPACITY(*l) = 0;
	free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
int length(ListDin l){
	 int i = 0;
	 while((ELMT(l, i) != VAL_UNDEF) && (i < CAPACITY(l))){
			i++;
	 }
	 return i;
}

/* *** Selektor INDEKS *** */
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
IdxType getLastIdx(ListDin l){
	 return length(l)-1; // selalu rata kiri
}

/* ********** Test Indeks yang valid ********** */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValid(ListDin l, IdxType i){
	 return (i >= 0) && (i < CAPACITY(l));
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */
boolean isIdxEff(ListDin l, IdxType i){
	 return ((i >= 0) && (i < length(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
boolean isEmpty(ListDin l){
	 return length(l) == 0;
}
/* *** Test list penuh *** */
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean isFull(ListDin l){
	 return length(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
			IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void readList(ListDin *l){
	int i;
	int n = IDX_UNDEF;
	do {
		scanf("%d", &n);
	} while ((n < 0) || (n > CAPACITY(*l)));
	for (i = 0; i < n; i++){
		scanf("%d", &ELMT(*l,i));
	}
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
	 antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
	 di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
void displayList(ListDin l){
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
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
	 int i;
	ListDin l;
	CreateListDin(&l, CAPACITY(l1));
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
/* *** Operasi pembandingan list : < =, > *** */
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
boolean isListEqual(ListDin l1, ListDin l2){
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
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan indeks tak terdefinisi (VAL_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */
IdxType indexOf(ListDin l, ElType val){
	 int i;
	for (i = 0; i < length(l); i++){
		if (ELMT(l, i) == val){
			return i;
		}
	}
	return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
				min berisi nilai minimum l */
void extremes(ListDin l, ElType *max, ElType *min){
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
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
void copyList(ListDin lIn, ListDin *lOut){
	 CreateListDin(lOut, CAPACITY(lIn));
	int i;
	for(i = 0; i < length(lIn); i++){
		ELMT(*lOut, i) = ELMT(lIn, i);
	}
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
ElType sumList(ListDin l){
	 ElType sum = 0, i;
	for(i = 0; i < length(l); i++){
		sum += ELMT(l, i);
	}
	return sum;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
	 int i, cnt = 0;
	for(i = 0; i < length(l); i++){
		if (ELMT(l, i) == val) cnt++;
	}
	return cnt;
}
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
boolean isAllEven(ListDin l){
	 int i;
	for (i = 0; i < length(l); i++){
		if (ELMT(l, i) % 2 != 0){
			return false;
		}
	}
	return true;
}

/* ********** SORTING ********** */
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
	 algoritma bebas */
void sort(ListDin *l, boolean asc){
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
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
void insertLast(ListDin *l, ElType val){
	 ELMT(*l, length(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteLast(ListDin *l, ElType *val){
	 *val = ELMT(*l, length(*l)-1);
	 ELMT(*l, length(*l)-1) = VAL_UNDEF;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
void growList(ListDin *l, int num){
	 ListDin temp; int i;
	copyList(*l, &temp);
	dealocate(l);
	CreateListDin(l, length(temp) + num);
	CAPACITY(*l) = CAPACITY(temp) + num;
	for(i = 0; i < length(temp); i++){
		ELMT(*l, i) = ELMT(temp, i);
	}
	dealocate(&temp);
}

/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
void shrinkList(ListDin *l, int num){
	 ListDin temp; int i;
	copyList(*l, &temp);
	dealocate(l);
	CreateListDin(l, CAPACITY(temp) - num);
	CAPACITY(*l) = CAPACITY(temp) - num;
	for(i = 0; i < length(temp); i++){
		ELMT(*l, i) = ELMT(temp, i);
	}
	dealocate(&temp);
}

/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
void compactList(ListDin *l){
	 ListDin temp; int i;
	copyList(*l, &temp);
	realloc(BUFFER(*l), length(temp) * sizeof(ElType));
	CAPACITY(*l) = length(temp);
	for(i = 0; i < length(temp); i++){
		ELMT(*l, i) = ELMT(temp, i);
	}
	dealocate(&temp);
}

#endif
