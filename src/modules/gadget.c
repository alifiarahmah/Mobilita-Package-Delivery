#include <stdio.h>
#include "gadget.h"

/* Proses: Menuliskan output nama Gadget secara lengkap */
/* Daftar gadget:
    1. Kain Pembungkus Waktu (800 Yen), gadgetType 'A'
	2. Senter Pembesar (1200 Yen), gadgetType 'B'
	3. Pintu Kemana Saja (1500 Yen) gadgetType 'C'
	4. Mesin Waktu (3000 Yen) gadgetType 'D'
*/
void printGadgetName(Gadget x){
    if(x == 'A'){
        printf("Kain Pembungkus Waktu");
    } else if (x == 'B'){
        printf("Senter Pembesar");
    } else if (x == 'C'){
        printf("Pintu Kemana Saja");
    } else if (x == 'D'){
        printf("Mesin Waktu");
    }
}
