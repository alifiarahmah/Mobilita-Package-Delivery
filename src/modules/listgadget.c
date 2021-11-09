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
#ifndef IDX_UNDEF
	#define IDX_UNDEF -1
#endif
/* Indeks tak terdefinisi*/
#define VAL_UNDEF '0'
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct {
	Gadget contents[MAXCAP]; /* memori tempat penyimpan elemen (container) */
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
	int count = 0;
	while(i < CAPACITY(l)){
        while (ELMT(l,i) != VAL_UNDEF) {
            count++;
        }
        i++;
	}
	return count;
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
	int i;
    int j = 1;
    for (i=0; i<CAPACITY(l); i++) {
        printf("%d. ", (i+1));
        if (ELMT(l,i) != VAL_UNDEF) {
            if (ELMT(l,i) == "Kain Pembungkus Waktu") {
                printf("Kain Pembungkus Waktu (800 Yen)\n");
            } else if (ELMT(l,i) == "Senter Pembesar") {
                printf("Senter Pembesar (1200 Yen)\n");
            } else if (ELMT(l,i) == "Pintu Kemana Saja") {
                printf("Pintu Kemana Saja (1500 Yen)\n");
            } else if (ELMT(l,i) == "Mesin Waktu") {
                printf("Mesin Waktu (3000 Yen)\n");
            }
        } else {
            printf("-\n");
        }
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
int indexOfListGadget(ListGadget l, Gadget val){}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN ********** */
/* Proses: Menambahkan val sebagai elemen dalam list, di indeks tempat VAL_UNDEF pertama */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
void insertGadget(ListGadget *l, Gadget val){
	int i = 0;
	while(ELMT(*l, i) != VAL_UNDEF){
		i++;
	}
	ELMT(*l, i) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteGadget(ListGadget *l, int idx, Gadget *val){
    *val = ELMT(*l,idx);
    ELMT(*l,idx) = VAL_UNDEF;
}

/* Proses: Menampilkan antarmuka pembelian gadget */
/* I.S. Mobita berada di Headquarter, banyak gadget dalam inventory tidak melebihi capacity. */
/*      Terdapat uang sebesar money yen, uang bisa kosong */
/* F.S. Jika list gadget tidak kosong dan uang cukup, gadget yang terbeli masuk ke inventory */
/* 		Jika pembelian gagal, menuliskan pesan. */
void buyGadget(ListGadget *l, int money){
	if(!isFullListGadget(*l)){
        char command, gtype;
        int cost;
		printf("Uang anda sekarang: %d Yen\n", money);
		printf("Gadget yang tersedia:\n"); // iterasi pake list
		printf("1. Kain Pembungkus Waktu (800 Yen)\n");
		printf("2. Senter Pembesar (1200 Yen)\n");
		printf("3. Pintu Kemana Saja (1500 Yen)\n");
		printf("4. Mesin Waktu (3000 Yen)\n");
		printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
		printf("\nENTER COMMAND: ");
        scanf("%c", &command);
        if (command == '1'){
            cost = 800; // Kain pembungkus waktu
            gtype = 'A';
        } else if (command == '2'){
            cost = 1200; // Senter pembesar
            gtype = 'B';
        } else if (command == '3'){
            cost = 1500; // Pintu kemana saja
            gtype = 'C';
        } else if (command == '4'){
            cost = 3000; // Mesin waktu
            gtype = 'D';
        }
        if (money >= cost){
            money -= cost;
            insertGadget(l, gtype);
            printGadgetName(gtype);
            printf(" berhasil dibeli.\n");
        } else {
            printf("Uang tidak cukup untuk membeli Gadget!\n");
        }
	} else { // list gadget penuh
		printf("Inventory anda penuh. Anda tidak bisa membeli gadget baru.\n");
	}
}

/* Proses: Menampilkan antarmuka pemakaian gadget */
/* I.S. Banyak gadget dalam inventory tidak melebihi capacity */
/* F.S Jika pemakaian berhasil, gadget yang terpakai menghilang dari inventory */
/*     Jika pemakaian gagal, menuliskan pesan */
void useGadget(ListGadget *l) {
    int i;
    int j = 1;
    int val;
    for (i=0; i<CAPACITY(*l); i++) {
        printf("%d. ", (i+1));
        if (ELMT(*l,i) != VAL_UNDEF) {
            if (ELMT(*l,i) == '"Kain Pembungkus Waktu"') {
                printf("Kain Pembungkus Waktu (800 Yen)\n");
            } else if (ELMT(*l,i) == "Senter Pembesar") {
                printf("Senter Pembesar (1200 Yen)\n");
            } else if (ELMT(*l,i) == "Pintu Kemana Saja") {
                printf("Pintu Kemana Saja (1500 Yen)\n");
            } else if (ELMT(*l,i) == "Mesin Waktu") {
                printf("Mesin Waktu (3000 Yen)\n");
            }
        } else {
            printf("-\n");
        }
    }
    printf("\nENTER COMMAND: ");
    /* Sesuai Command*/
    if (ELMT(*l,COMMAND-1) != VAL_UNDEF) {
        deleteGadget(l,COMMAND-1,&val);
    }
    else {
		printf("Tidak ada Gadget yang dapat digunakan!\n");
	}
}

#endif
