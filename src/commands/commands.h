#ifndef COMMAND_H
#define COMMAND_H

#include "../modules/adt.h"

/* buy.c */
void buy(POINT posNow, Matrix lokMat, ListGadget *l, int *money);

/* dropoff.c */
void dropOff(Stack *s, POINT p);

/* help.c */
void help();

/* inprogress.c */
void inProgress(Queue backpack);

/* inventory.c */
void inventory(ListGadget *l);

/* map.c */
void initMap (Matrix *peta);

void isiMap (Matrix *peta, int jumlah);

char posisiSkrg (POINT posNow, Matrix lokMat);

void printBerwarna (int pilihan, char bangunan);

int posisiToIdx(char bangunan);

boolean cekAdj (Matrix adjMat, char bangunan, char posisiSkrg);

boolean cekToDo (char bangunan, Queue toDo);

void Map (Matrix adjMat, Matrix lokMat, POINT posNow, Queue toDo, Stack dropOff);

/* move.c */
void move(Matrix adjMat, POINT *posNow, int *time, ListDin lBuilding);

/* pickup.c */
void pickUp(POINT posNow, Matrix LokMat, LList *todo, LList *inprogress, Stack *tas, int *incTime);

/* todolist.c */
void todolist(Pesanan *L, Queue *Q);

#endif