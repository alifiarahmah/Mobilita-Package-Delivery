/* Struktur data Item
   Jenis tipe Item:
   - Normal Item, type 'N', expired -1
   - Heavy Item, type 'H', expired -1
   - Perishable Item, tipe 'P', dengan expiry tertentu.
*/

#ifndef ITEM_H
#define ITEM_H

typedef struct item
{
   char type;
   int expired;
} Item;

#endif
