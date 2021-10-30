/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "boolean.h"

#ifndef IDX_UNDEF
	#define IDX_UNDEF -1
#endif
#define QUEUE_CAPACITY 100

/* Definisi elemen dan address */
typedef int ElType;
typedef struct {
	ElType buffer[QUEUE_CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD_Q(q) (q).idxHead
#define IDX_TAIL_Q(q) (q).idxTail
#define     HEAD_Q(q) (q).buffer[(q).idxHead]
#define     TAIL_Q(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
void CreateQueue(Queue *q){
	IDX_HEAD_Q(*q) = IDX_UNDEF;
	IDX_TAIL_Q(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isEmptyQ(Queue q){
	return (IDX_HEAD_Q(q) == IDX_UNDEF) && (IDX_TAIL_Q(q) == IDX_UNDEF);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai QUEUE_CAPACITY-1 */
boolean isFullQ(Queue q){
	return (IDX_HEAD_Q(q) == 0) && (IDX_TAIL_Q(q) == QUEUE_CAPACITY-1);
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int lengthQ(Queue q){
	if (isEmptyQ(q)){
		return 0;
	}
	return (IDX_TAIL_Q(q) - IDX_HEAD_Q(q) + 1);
}

/* *** Primitif Add/Delete *** */

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL_Q yang baru, IDX_TAIL_Q "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL_Q baru  */
void enqueueQ(Queue *q, ElType val){
	int i, tmpIdx = 0;
	if (isEmptyQ(*q)){
		IDX_HEAD_Q(*q) = 0;
		IDX_TAIL_Q(*q) = 0;
	} else {
		if (IDX_TAIL_Q(*q) == (QUEUE_CAPACITY-1)){
			for(i = IDX_HEAD_Q(*q); i <= IDX_TAIL_Q(*q); i++){
				(*q).buffer[i - IDX_HEAD_Q(*q)] = (*q).buffer[i];
			}
			IDX_TAIL_Q(*q) -= IDX_HEAD_Q(*q);
			IDX_HEAD_Q(*q) = 0;
		}
		IDX_TAIL_Q(*q)++;
	}
	TAIL_Q(*q) = val;
}

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD_Q pd I.S., HEAD_Q dan IDX_HEAD_Q "mundur"; 
        q mungkin kosong */
void dequeueQ(Queue *q, ElType *val){
	*val = HEAD_Q(*q);
	if (IDX_HEAD_Q(*q) == IDX_TAIL_Q(*q)){
		IDX_HEAD_Q(*q) = IDX_UNDEF;
		IDX_TAIL_Q(*q) = IDX_UNDEF;
	} else {
		IDX_HEAD_Q(*q)++;
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
	if (IDX_HEAD_Q(q) == 0 && IDX_TAIL_Q(q) == 0){
		printf("%d", HEAD_Q(q));
	} else if (!isEmptyQ(q)){
		for(i = IDX_HEAD_Q(q); i <= IDX_TAIL_Q(q); i++){
			printf("%d", (q).buffer[i]);
			if (i < IDX_TAIL_Q(q)) printf(",");
		}
	}
	printf("]");
}

#endif
