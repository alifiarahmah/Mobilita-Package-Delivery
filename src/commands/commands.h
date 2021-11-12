#ifndef COMMAND_H
#define COMMAND_H

/* buy.c */
void buy(int money, ListGadget inventory);

/* dropoff.c */
void dropOff(Stack *s, POINT p);

/* help.c */
void help();

/* inprogress.c */
void inProgress(Queue backpack);

/* Map.c */
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
void pickUp(POINT posNow, Matrix LokMat, Queue *queuePesanan, LList *todo, Stack *tas);

/* todolist.c */
void todolist(Pesanan *L, Queue *Q);

#endif