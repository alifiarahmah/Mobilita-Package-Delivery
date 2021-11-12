#include <stdio.h>
#include "../modules/adt.h"
#include "commands.h"

void dropOff(Stack *s, POINT p) {
    Pesanan val;
    if (DROP_OFF(TOP(*s)) == p) {
        if (ITEM(TOP(*s)) == 'N') {
            printf("Pesanan Normal Item berhasil diantarkan");
            printf("Uang yang didapatkan: 200 Yen");
        } else if (ITEM(TOP(*s)) == 'H') {
            printf("Pesanan Heavy Item berhasil diantarkan");
            printf("Uang yang didapatkan: 400 Yen");
            printf("Ability yang didapatkan: Speed Boost");
        } else if (ITEM(TOP(*s)) == 'P') {
            printf("Pesanan Perishable Item berhasil diantarkan");
            printf("Uang yang didapatkan: 400 Yen");
            printf("Ability yang didapatkan: Increase Capacity");
        } else if (ITEM(TOP(*s)) == 'V') {
            printf("Pesanan VIP Item berhasil diantarkan");
            printf("Uang yang didapatkan: 600 Yen");
            printf("Ability yang didapatkan: Return To Sender");
        }
        pop(s,&val);
    } else {
        printf("Tidak terdapat pesanan yang dapat diantarkan");
    }
}
