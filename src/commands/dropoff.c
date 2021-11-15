#include <stdio.h>
#include "../modules/adt.h"
#include "commands.h"

void dropOff(Stack *s, POINT p) {
    Pesanan val;
    if (DROP_OFF(TOP(*s)) == p) { /* data tipe Item gaada point jadi abakal eror disini */
        if (TYPE(TOP(*s)) == 'N') {
            printf("Pesanan Normal Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 200 Yen\n");
        } else if (TYPE(TOP(*s)) == 'H') {
            printf("Pesanan Heavy Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 400 Yen\n");
            printf("Ability yang didapatkan: Speed Boost\n");
        } else if (TYPE(TOP(*s)) == 'P') {
            printf("Pesanan Perishable Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 400 Yen\n");
            printf("Ability yang didapatkan: Increase Capacity\n");
        } else if (TYPE(TOP(*s)) == 'V') {
            printf("Pesanan VIP Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 600 Yen\n");
            printf("Ability yang didapatkan: Return To Sender\n");
        }
        pop(s,&val);
    } else {
        printf("Tidak terdapat pesanan yang dapat diantarkan\n");
    }
}
