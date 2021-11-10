#include <stdio.h>
#include "gadget.h"

/* Proses: Menuliskan output nama Gadget secara lengkap */
/* Daftar gadget:
    1. Kain Pembungkus Waktu (800 Yen), gadgetType 'A'
	2. Senter Pembesar (1200 Yen), gadgetType 'B'
	3. Pintu Kemana Saja (1500 Yen) gadgetType 'C'
	4. Mesin Waktu (3000 Yen) gadgetType 'D'
*/
Gadget getGadgetName(char gtype){
	char gadget;
	switch(gtype){
		case 'A':
			gadget = 'Kain Pembungkus Waktu';
		case 'B':
			gadget = 'Senter Pembesar';
		case 'C':
			gadget = 'Pintu Kemana Saja';
		case 'D':
			gadget = 'Mesin Waktu';
	}
	return gadget;
}

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

int getGadgetPrice(Gadget x){
    int money;
    if(x == 'A'){
        money = 800;
    } else if (x == 'B'){
        money = 1200;
    } else if (x == 'C'){
        money = 1500;
    } else if (x == 'D'){
        money = 3000;
    }
    return money;
}
