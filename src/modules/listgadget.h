/* File: listgadget.h */

/* MODUL PENYIMPANAN GADGET YANG SUDAH DIBELI */
/* modifikasi ADT List Statis */

#ifndef LISTGADGET_H
#define LISTGADGET_H

#include "boolean.h"
#include "gadget.h"

/*  Kamus Umum */
#define MAXCAP 100
/* Kapasitas penyimpanan */
#ifndef IDX_UNDEF
	#define IDX_UNDEF -1
#endif
/* Indeks tak terdefinisi*/
// FIXME: jadi VAL_UNDEF nya '0' atau -999?
#define VAL_UNDEF '0'
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct {
	Gadget contents[5]; /* memori tempat penyimpan elemen (container) */
} ListGadget;
/* Indeks yang digunakan [0..4] */
/* Jika l adalah ListGadget, cara deklarasi dan akses: */
/* Deklarasi : l : ListGadget */
/* Maka cara akses:
	 GADGET_ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
	 List kosong: semua elemen bernilai VAL_UNDEF
	 Definisi elemen pertama: GADGET_ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define GADGET_ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListGadget(ListGadget *l);
/* I.S. l sembarang */
/* F.S. Terbentuk ListGadget l kosong dengan kapasitas 5 */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF, set capacity 5 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListGadget(ListGadget l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** Test Indeks yang valid ********** */
boolean isIdxListGadgetValid(ListGadget l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxListGadgetEff(ListGadget l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListGadget(ListGadget l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullListGadget(ListGadget l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void displayListGadget(ListGadget l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
	 siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
	 karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListGadget(ListGadget l, Gadget val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan GADGET_ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertGadget(ListGadget *l, Gadget val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void deleteGadget(ListGadget *l, int idx, Gadget *val);
/* Proses : Menghapus elemen List pada indeks tertentu */
/* I.S. List tidak kosong, idx indeks yang valid */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* void buyGadget(ListGadget *l, int money); */
/* Proses: Menampilkan antarmuka pembelian gadget */
/* I.S. Mobita berada di Headquarter, banyak gadget dalam inventory tidak melebihi capacity */
/* F.S. Jika pembelian berhasil, gadget yang terbeli masuk ke inventory */
/* 		Jika pembelian gagal, menuliskan pesan */
/* Note: Pindah ke /src/commands/buy.c dengan nama fungsi buy() */

/* void useGadget(ListGadget *l); */
/* Proses: Menampilkan antarmuka pemakaian gadget */
/* I.S. Banyak gadget dalam inventory tidak melebihi capacity */
/* F.S Jika pemakaian berhasil, gadget yang terpakai menghilang dari inventory */
/*     Jika pemakaian gagal, menuliskan pesan */
/* Note: Pindah ke /src/commands/inventory.c dengan nama fungsi inventory() */

#endif
