#include <stdio.h>

#include "commands/commands.h"
#include "modules/adt.h"
#include "main_menu.h"
#include "read_file.h"

/* Kerangka dari fungsi utama*/
int main(){
    Matrix peta,adj;
    Queue pesanan;
    ListDin lBuilding;
    char command[50];
    Word fileKonfig;
    POINT posisi;
    Stack tas;

    ListGadget gadgetInventory;
    CreateListGadget(&gadgetInventory);
    int money = 0; // uang Mobita
    int time = 0; // waktu berjalan

    CreateStack(&tas);
    CreateQueue(&pesanan);
    MainMenu(&fileKonfig);
    bacaFile(fileKonfig,&peta,&adj,&pesanan,&lBuilding);
    posisi = elmtToPoint(peta,'8');
    Name(posisi) = '8';

    do{
        printf("\n\n");
        printf("Mobita berada di titik %c",MAT_ELMT(peta,Absis(posisi),Ordinat(posisi)));
        TulisPOINT(posisi);
        printf("\n");
        printf("Waktu: %d\n", time);
        printf("Uang yang dimiliki: %d Yen\n", money);
        printf("ENTER COMMAND: ");
        scanf("%s",command);
        if (cekKataSama(command,"MOVE")){
            move(adj,&posisi,&time,lBuilding);
        }
        else if (cekKataSama(command,"PICK_UP")){
            printf("PICK_UP");
        }
        else if (cekKataSama(command,"DROP_OFF")){
            dropOff(&tas,posisi);
        }
        else if (cekKataSama(command,"MAP")){
            Map(adj,peta,posisi,pesanan,tas);
        }
        else if (cekKataSama(command,"TO_DO")){
            printf("TO_DO");
        }
        else if (cekKataSama(command,"IN_PROGRESS")){
            inProgress(pesanan);
        }
        else if (cekKataSama(command,"BUY")){
            buy(&gadgetInventory, &money);
        }
        else if (cekKataSama(command,"INVENTORY")){
            inventory(&gadgetInventory);
            // TODO: tambah efek dari pemakaian tiap gadget
        }
        else if (cekKataSama(command,"HELP")){
            help();
        }
        else if (cekKataSama(command,"EXIT")){
            printf("TERIMA KASIH SUDAH BERMAIN\n");
        }
        else{
            printf("Masukan command tidak valid, coba lagi!");
        }
    }while(!cekKataSama(command,"EXIT"));
    exit(0);
}
