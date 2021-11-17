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
#define LISTPOS_CAPACITY 100
/* Kapasitas penyimpanan */
#ifndef IDX_UNDEF
	#define IDX_UNDEF -1
#endif
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ListPosElType;  /* type elemen List */
typedef struct {
	 ListPosElType contents[LISTPOS_CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListPos;
/* Indeks yang digunakan [0..LISTPOS_CAPACITY-1] */
/* Jika l adalah ListPos, cara deklarasi dan akses: */
/* Deklarasi : l : ListPos */
/* Maka cara akses: 
	 LISTPOS_ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
	 List kosong: semua elemen bernilai VAL_UNDEF
	 Definisi elemen pertama: LISTPOS_ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define LISTPOS_ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l){
	/* I.S. l sembarang */
	/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
	/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
	int i;
	for (i = 0; i < LISTPOS_CAPACITY; i++){
		LISTPOS_ELMT(*l, i) = VAL_UNDEF;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListPos(ListPos l){
	/* Mengirimkan banyaknya elemen efektif List */
	/* Mengirimkan nol jika List kosong */
	int i = 0;
	while((LISTPOS_ELMT(l,i) != VAL_UNDEF) && (i < LISTPOS_CAPACITY)){
		i++;
	}
	return i;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidLP(ListPos l, int i){
	/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
	/* yaitu antara indeks yang terdefinisi utk container*/
	return (i >= 0) && (i < LISTPOS_CAPACITY);
}

boolean isIdxEffLP(ListPos l, int i){
	/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
	/* yaitu antara 0..lengthListPos(l)-1 */
	return ((i >= 0) && (i < lengthListPos(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLP(ListPos l){
	/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
	return lengthListPos(l) == 0;
} 

/* *** Test List penuh *** */
boolean isFullLP(ListPos l){
	/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
	return lengthListPos(l) == LISTPOS_CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListPos(ListPos *l){
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
	} while ((n < 0) || (n > LISTPOS_CAPACITY));
	for (i = 0; i < n; i++){
		scanf("%d", &LISTPOS_ELMT(*l,i));
	}
}
void displayListPos(ListPos l){
	/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
		siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
		karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
	/* I.S. l boleh kosong */
	/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika List kosong : menulis [] */
	int i;
	printf("[");
	for(i = 0; i < lengthListPos(l); i++){
		printf("%d", LISTPOS_ELMT(l,i));
		if (i < lengthListPos(l)-1) {
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
		for(i = 0; i < lengthListPos(l1); i++){
			LISTPOS_ELMT(l, i) =  LISTPOS_ELMT(l1, i) + LISTPOS_ELMT(l2, i);
		}
	} else {
		for(i = 0; i < lengthListPos(l1); i++){
			LISTPOS_ELMT(l, i) =  LISTPOS_ELMT(l1, i) - LISTPOS_ELMT(l2, i);
		}
	}
	return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListPosEqual(ListPos l1, ListPos l2){
	/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
		elemennya sama */
	if (lengthListPos(l1) != lengthListPos(l2)) return false;
	int i = 0;
	boolean check = (LISTPOS_ELMT(l1, i) == LISTPOS_ELMT(l2, i));
	while (check && (i < lengthListPos(l1))){
		if (LISTPOS_ELMT(l1, i) != LISTPOS_ELMT(l2, i)){
			check = false;
		}
		i++;
	}
	return check;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfPos(ListPos l, ListPosElType val){
	/* Search apakah ada elemen List l yang bernilai val */
	/* Jika ada, menghasilkan indeks i terkecil, dengan LISTPOS_ELMT(l,i) = val */
	/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
	/* Skema Searching yang digunakan bebas */
	int i;
	for (i = 0; i < lengthListPos(l); i++){
		if (LISTPOS_ELMT(l, i) == val){
			return i;
		}
	}
	return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremesPos(ListPos l, ListPosElType *max, ListPosElType *min){
	/* I.S. List l tidak kosong */
	/* F.S. Max berisi nilai terbesar dalam l;
					Min berisi nilai terkecil dalam l */
	int i;
	*max = LISTPOS_ELMT(l, 0); *min = LISTPOS_ELMT(l, 0);
	for(i = 1; i < lengthListPos(l); i++){
		if (LISTPOS_ELMT(l, i) > *max){
			*max = LISTPOS_ELMT(l, i);
		}
		if (LISTPOS_ELMT(l, i) < *min){
			*min = LISTPOS_ELMT(l, i);
		}
	}
}

/* ********** OPERASI LAIN ********** */
boolean isAllEvenPos(ListPos l){
	/* Menghasilkan true jika semua elemen l genap */
	int i;
	for (i = 0; i < lengthListPos(l); i++){
		if (LISTPOS_ELMT(l, i) % 2 != 0){
			return false;
		}
	}
	return true;
}

/* ********** SORTING ********** */
void sortPos(ListPos *l, boolean asc){
	/* I.S. l boleh kosong */
	/* F.S. Jika asc = true, l terurut membesar */
	/*      Jika asc = false, l terurut mengecil */
	/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
		algoritma bebas */
	int i, j;
	ListPosElType temp;
	if (asc){ // ascending order
		for(i = 0; i < lengthListPos(*l) - 1; i++){
			for(j = i+1; j < lengthListPos(*l); j++){
				if (LISTPOS_ELMT(*l, i) > LISTPOS_ELMT(*l, j)){
					temp = LISTPOS_ELMT(*l, i);
					LISTPOS_ELMT(*l, i) = LISTPOS_ELMT(*l, j);
					LISTPOS_ELMT(*l, j) = temp;
				}
			}
		}
	} else { // descending order
		for(i = 0; i < lengthListPos(*l) - 1; i++){
			for(j = i+1; j < lengthListPos(*l); j++){
				if (LISTPOS_ELMT(*l, i) < LISTPOS_ELMT(*l, j)){
					temp = LISTPOS_ELMT(*l, i);
					LISTPOS_ELMT(*l, i) = LISTPOS_ELMT(*l, j);
					LISTPOS_ELMT(*l, j) = temp;
				}
			}
		}
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastPos(ListPos *l, ListPosElType val){
	/* Proses: Menambahkan val sebagai elemen terakhir List */
	/* I.S. List l boleh kosong, tetapi tidak penuh */
	/* F.S. val adalah elemen terakhir l yang baru */
	LISTPOS_ELMT(*l, lengthListPos(*l)) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastPos(ListPos *l, ListPosElType *val){
	/* Proses : Menghapus elemen terakhir List */
	/* I.S. List tidak kosong */
	/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
	/*      Banyaknya elemen List berkurang satu */
	/*      List l mungkin menjadi kosong */
	*val = LISTPOS_ELMT(*l,lengthListPos(*l)-1);
	LISTPOS_ELMT(*l, lengthListPos(*l)-1) = VAL_UNDEF;
}

#endif