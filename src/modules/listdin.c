/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
	 memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/*  Kamus Umum */
#ifndef IDX_UNDEF
	#define IDX_UNDEF -1
#endif
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
		ElType *buffer; /* memori tempat penyimpan elemen (container) */
		int nEff;       /* >=0, banyaknya elemen efektif */
		int capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
	 l.nEff      untuk mengetahui banyaknya elemen
	 l.buffer    untuk mengakses seluruh nilai elemen list
	 l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
	list kosong: l.nEff = 0
	Definisi elemen pertama : l.buffer[i] dengan i=0
	Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT_DIN(l, i) (l).buffer[i]
#define LISTDIN_CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
void CreateListDin(ListDin *l, int capacity){ 
	LISTDIN_CAPACITY(*l) = capacity;
	NEFF(*l) = 0;
	BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
}

/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, LISTDIN_CAPACITY(l)=0; NEFF(l)=0 */
void dealocate(ListDin *l){
	LISTDIN_CAPACITY(*l) = 0;
	NEFF(*l) = 0;
	free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
int lengthListDin(ListDin l){
	return NEFF(l);
}

/* *** Selektor INDEKS *** */
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
IdxType getLastIdx(ListDin l){
	return lengthListDin(l)-1;
}

/* ********** Test Indeks yang valid ********** */
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValidLD(ListDin l, int i){
	return (i >= 0) && (i < LISTDIN_CAPACITY(l));
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
boolean isIdxEffLD(ListDin l, IdxType i){
	return (i >= 0) && (i < lengthListDin(l));
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test list kosong *** */
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
boolean isEmptyDin(ListDin l){
	return lengthListDin(l) == 0;
}

/* *** Test list penuh *** */
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean isFullLD(ListDin l){
	return lengthListDin(l) == LISTDIN_CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */

/* *** Mendefinisikan isi list dari pembacaan *** */
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= LISTDIN_CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= LISTDIN_CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
			0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void readListDin(ListDin *l){
	int n = IDX_UNDEF, i = 0;
	do {
		scanf("%d", &n);
	} while ((n < 0) || (n > LISTDIN_CAPACITY(*l)));
	NEFF(*l) = n;
	for(i = 0; i < NEFF(*l); i++){
		scanf("%d", &ELMT_DIN(*l, i));
	}
}

/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
	 antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
	 di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
void displayListDin(ListDin l){
	int i;
	printf("[");
	for(i = 0; i < lengthListDin(l); i++){
		printf("%d", ELMT_DIN(l,i));
		if (i < lengthListDin(l)-1) {
			printf(",");
		}
	}
	printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
	int i;
	ListDin l;
	CreateListDin(&l, NEFF(l1));
	NEFF(l) = NEFF(l1);
	if(plus){
		for(i = 0; i < lengthListDin(l); i++){
			ELMT_DIN(l, i) = ELMT_DIN(l1, i) + ELMT_DIN(l2, i);
		}
	} else {
		for(i = 0; i < lengthListDin(l); i++){
			ELMT_DIN(l, i) = ELMT_DIN(l1, i) - ELMT_DIN(l2, i);
		}
	}
	return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
boolean isListDinEqual(ListDin l1, ListDin l2){
	if (lengthListDin(l1) != lengthListDin(l2)) return false;
	int i = 0;
	boolean check = ELMT_DIN(l1, i) == ELMT_DIN(l2, i);
	while (check && (i < lengthListDin(l1))){
		if (ELMT_DIN(l1, i) != ELMT_DIN(l2, i)){
			check = false;
		}
		i++;
	}
	return check;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
IdxType indexOfDin(ListDin l, ElType val){
	int i = 0; boolean found = false;
	for (i = 0; i < lengthListDin(l); i++){
		if (ELMT_DIN(l, i) == val){
			return i;
		}
	}
	return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
				min berisi nilai minimum l */
void extremesDin(ListDin l, ElType *max, ElType *min){
	int i;
	*max = ELMT_DIN(l, 0); *min = ELMT_DIN(l, 0);
	for(i = 1; i < lengthListDin(l); i++){
		if (ELMT_DIN(l, i) > *max){
			*max = ELMT_DIN(l, i);
		}
		if (ELMT_DIN(l, i) < *min){
			*min = ELMT_DIN(l, i);
		}
	}
}

/* ********** OPERASI LAIN ********** */
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
void copyList(ListDin lIn, ListDin *lOut){
	CreateListDin(lOut, LISTDIN_CAPACITY(lIn));
	NEFF(*lOut) = NEFF(lIn);
	int i;
	for(i = 0; i < lengthListDin(lIn); i++){
		ELMT_DIN(*lOut, i) = ELMT_DIN(lIn, i);
	}
}

/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
ElType sumList(ListDin l){
	ElType sum = 0, i;
	for(i = 0; i < lengthListDin(l); i++){
		sum += ELMT_DIN(l, i);
	}
	return sum;
}

/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
	int i, cnt = 0;
	for(i = 0; i < lengthListDin(l); i++){
		if (ELMT_DIN(l, i) == val) cnt++;
	}
	return cnt;
}

/* Menghasilkan true jika semua elemen l genap. l boleh kosong */
boolean isAllEvenDin(ListDin l){
	int i;
	for (i = 0; i < lengthListDin(l); i++){
		if (ELMT_DIN(l, i) % 2 != 0){
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
void sortDin(ListDin *l, boolean asc){
	int i, j;
	ElType temp;
	if (asc){ // ascending order
		for(i = 0; i < lengthListDin(*l) - 1; i++){
			for(j = i+1; j < lengthListDin(*l); j++){
				if (ELMT_DIN(*l, i) > ELMT_DIN(*l, j)){
					temp = ELMT_DIN(*l, i);
					ELMT_DIN(*l, i) = ELMT_DIN(*l, j);
					ELMT_DIN(*l, j) = temp;
				}
			}
		}
	} else { // descending order
		for(i = 0; i < lengthListDin(*l) - 1; i++){
			for(j = i+1; j < lengthListDin(*l); j++){
				if (ELMT_DIN(*l, i) < ELMT_DIN(*l, j)){
					temp = ELMT_DIN(*l, i);
					ELMT_DIN(*l, i) = ELMT_DIN(*l, j);
					ELMT_DIN(*l, j) = temp;
				}
			}
		}
	}
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
void insertLastDin(ListDin *l, ElType val){
	ELMT_DIN(*l, lengthListDin(*l)) = val;
	NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteLastDin(ListDin *l, ElType *val){
	*val = ELMT_DIN(*l, lengthListDin(*l)-1);
	NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */

/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
void growList(ListDin *l, int num){
	ListDin temp; int i;
	copyList(*l, &temp);
	dealocate(l);
	CreateListDin(l, lengthListDin(temp) + num);
	LISTDIN_CAPACITY(*l) = LISTDIN_CAPACITY(temp) + num;
	for(i = 0; i < lengthListDin(temp); i++){
		ELMT_DIN(*l, i) = ELMT_DIN(temp, i);
		NEFF(*l)++;
	}
	dealocate(&temp);
}

/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
void shrinkList(ListDin *l, int num){
	ListDin temp; int i;
	copyList(*l, &temp);
	dealocate(l);
	CreateListDin(l, LISTDIN_CAPACITY(temp) - num);
	LISTDIN_CAPACITY(*l) = LISTDIN_CAPACITY(temp) - num;
	for(i = 0; i < lengthListDin(temp); i++){
		ELMT_DIN(*l, i) = ELMT_DIN(temp, i);
		NEFF(*l)++;
	}
	dealocate(&temp);
}

/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
void compactList(ListDin *l){
	ListDin temp; int i;
	void *ptr;

	copyList(*l, &temp);
	ptr = realloc(BUFFER(*l), lengthListDin(temp) * sizeof(ElType));
	LISTDIN_CAPACITY(*l) = lengthListDin(temp);
	for(i = 0; i < lengthListDin(temp); i++){
		ELMT_DIN(*l, i) = ELMT_DIN(temp, i);
	}
	dealocate(&temp);
}

#endif
