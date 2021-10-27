/* File : pesanan.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef PESANAN_H
#define PESANAN_H

#include "point.h"
#include "boolean.h"

#define TIME_UNDEF -1
#define IDX_UNDEF -1
#define CAPACITY 30

/* Definisi elemen dan address */
typedef struct {
    int time;
    POINT pickup;
    POINT dropoff;
    char item;
    int Ptime;
} Pesanan;

typedef struct {
	Pesanan buffer[CAPACITY];
	int idxHead;
	int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika p adalah Pesanan dan q adalah Queue, maka akses elemen : */
#define TIME(p)     (p).time
#define PICK_UP(p)  (p).pickup
#define DROP_OFF(p) (p).dropoff
#define ITEM(p)     (p).item
#define PTIME(p)    (p).Ptime
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Selektor lain *** */
void SetPesanan(Pesanan *p, int tval, POINT pval, POINT dval, char ival, int Ptval);
/* I.S. pesanan p sembarang */
/* F.S. pesanan p terbentuk dengan sbb: */
/* - time bernilai tval */
/* - lokasi pick up bernilai pval */
/* - lokasi drop off bernilai dval */
/* - item bernilai ival */
/* - Ptime bernilai Ptval */

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Pesanan val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, Pesanan *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur";
        q mungkin kosong */

#endif
