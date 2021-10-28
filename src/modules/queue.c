/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef int ElType;
typedef struct {
	ElType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
void CreateQueue(Queue *q){
	IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isEmpty(Queue q){
	return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
boolean isFull(Queue q){
	return (IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITY-1);
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int length(Queue q){
	if (isEmpty(q)){
		return 0;
	}
	return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
}

/* *** Primitif Add/Delete *** */

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
void enqueue(Queue *q, ElType val){
	int i, tmpIdx = 0;
	if (isEmpty(*q)){
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
	} else {
		if (IDX_TAIL(*q) == (CAPACITY-1)){
			for(i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++){
				(*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
			}
			IDX_TAIL(*q) -= IDX_HEAD(*q);
			IDX_HEAD(*q) = 0;
		}
		IDX_TAIL(*q)++;
	}
	TAIL(*q) = val;
}

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
void dequeue(Queue *q, ElType *val){
	*val = HEAD(*q);
	if (IDX_HEAD(*q) == IDX_TAIL(*q)){
		IDX_HEAD(*q) = IDX_UNDEF;
		IDX_TAIL(*q) = IDX_UNDEF;
	} else {
		IDX_HEAD(*q)++;
	}
}

/* *** Display Queue *** */
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
void displayQueue(Queue q){
	int i;
	printf("[");
	if (IDX_HEAD(q) == 0 && IDX_TAIL(q) == 0){
		printf("%d", HEAD(q));
	} else if (!isEmpty(q)){
		for(i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
			printf("%d", (q).buffer[i]);
			if (i < IDX_TAIL(q)) printf(",");
		}
	}
	printf("]");
}

#endif
