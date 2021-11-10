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