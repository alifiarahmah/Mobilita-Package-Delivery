#include <stdio.h>
#include "../modules/adt.h"
#include "commands.h"

void dropOff(Stack *s, POINT p, int *money, char *output, int *incTime, int *timeSpeed) {
    Pesanan val;
    if (EQ(DROP_OFF(TOP(*s)),p)) { /* harus memakai adt pesanan untuk menunjukkan point dropnya dimana */
        if (TYPE(ITEM(TOP(*s))) == 'N') {
            printf("Pesanan Normal Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 200 Yen\n");
        } else if (TYPE(ITEM(TOP(*s))) == 'H') {
            printf("Pesanan Heavy Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 400 Yen\n");
            printf("Ability yang didapatkan: Speed Boost\n");
            *incTime--;
            if (*incTime == 1) {
                *timeSpeed = 10;
            }
            printf("Karena mendapat semangat, anda bergerak lebih cepat!\n");
        } else if (TYPE(ITEM(TOP(*s))) == 'P') {
            printf("Pesanan Perishable Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 400 Yen\n");
            printf("Ability yang didapatkan: Increase Capacity\n");
            increaseTasCapacity(s);
            printf("Kapasitas tas anda bertambah 1!\n");
        } else if (TYPE(ITEM(TOP(*s))) == 'V') {
            printf("Pesanan VIP Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 600 Yen\n");
            printf("Ability yang didapatkan: Return To Sender\n");
            printf("Anda dapat menggunakan perintah RETURN!\n");
        }
        *money += getItemPrice(ITEM(TOP(*s)));
        *output = TYPE(ITEM(TOP(*s)));
        pop(s,&val);
    } else {
        printf("Tidak terdapat pesanan yang dapat diantarkan\n");
        *output = TYPE_UNDEF;
    }
}
