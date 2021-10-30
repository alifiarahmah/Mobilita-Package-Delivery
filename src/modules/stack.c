/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "boolean.h"

#ifndef IDX_UNDEF
	#define IDX_UNDEF -1
#endif
#define STACK_CAPACITY 100

typedef int ElType;
typedef struct {
  ElType buffer[STACK_CAPACITY]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]

/* *** Konstruktor/Kreator *** */
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
void CreateStack(Stack *s){
	IDX_TOP(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isEmptyStack(Stack s){
	return IDX_TOP(s) == IDX_UNDEF;
}
/* Mengirim true jika tabel penampung nilai s stack penuh */
boolean isFullStack(Stack s){
	return IDX_TOP(s) == STACK_CAPACITY-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
void push(Stack *s, ElType val){
	IDX_TOP(*s)++;
	TOP(*s) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
void pop(Stack *s, ElType *val){
	*val = TOP(*s);
	IDX_TOP(*s)--;
}

#endif
