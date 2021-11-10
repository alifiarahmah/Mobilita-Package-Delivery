#include "boolean.h"
#include "item.h"

/* KREATOR */
/* I.S. x bebas
   F.S. Item x terdefinisi dengan tipe itemType dan expired expiryTime
*/
void createItem(Item *x, char itemType, int expiryTime){
	TYPE(*x) = itemType;
	EXPIRED(*x) = expiryTime;
}

boolean isItemEqual(Item a, Item b){
   return (TYPE(a) == TYPE(b)) && (EXPIRED(a) == EXPIRED(b));
}

Item getItemName(char type){
   char item;
	switch(type){
		case 'P':
			item = 'Perishabel Item';
		case 'N':
			item = 'Normal Item';
		case 'H':
			item = 'Heavy Item';
		case 'V':
			item = 'VIP Item';
	}
	return item;
}
/*mengembalikan nama item*/

int getItemPrice(Item x){
    int money;
    if(x == 'P'){
        money = 400;
    } else if (x == 'N'){
        money = 200;
    } else if (x == 'H'){
        money = 400;
    } else if (x == 'V'){
        money = 600;
    }
    return money;
}