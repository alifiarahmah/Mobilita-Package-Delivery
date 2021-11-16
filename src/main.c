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
    LList todo, inprogress;

    int money = 0; // uang Mobita
    int time = 0; // waktu berjalan
    int incTime = 1; // skala penambahan waktu

    CreateListGadget(&gadgetInventory);
    CreateStack(&tas);
    CreateQueue(&pesanan);
    MainMenu(&fileKonfig);
    bacaFile(fileKonfig,&peta,&adj,&pesanan,&lBuilding);
    posisi = elmtToPoint(peta,'8');
    Name(posisi) = '8';

    // temporary variables
    Pesanan val;

    do{
        printf("\n\n");
        printf("Mobita berada di titik %c",MAT_ELMT(peta,Absis(posisi),Ordinat(posisi)));
        TulisPOINT(posisi);
        printf("\n");
        printf("Waktu: %d\n", time);
        printf("Uang yang dimiliki: %d Yen\n", money);
        printf("ENTER COMMAND: ");
        startWord();
        for (int i = 0; i < currentWord.length; i ++) {
            command[i] = currentWord.contents[i];
        }
        command[currentWord.length] = '\0';
        if (cekKataSama(command,"MOVE")){
            move(adj,&posisi,&time,lBuilding, 1);
            
            // tiap pindah waktu, pindahin pesanan dari queue pesanan ke linkedlist todo
            if(TIME(HEAD(pesanan)) == time){
                dequeue(&pesanan, &val);
                insertLastLL(&todo, val);
            }
            // tiap pindah waktu, item yang lewat time limit perish

        }
        else if (cekKataSama(command,"PICK_UP")){
            pickUp(posisi, peta, &todo, &inprogress, &tas, &incTime);
        }
        else if (cekKataSama(command,"DROP_OFF")){
            dropOff(&tas,posisi);
        }
        else if (cekKataSama(command,"MAP")){
            Map(adj,peta,posisi,pesanan,tas);
        }
        else if (cekKataSama(command,"TO_DO")){
            todolist(pesanan);
        }
        else if (cekKataSama(command,"IN_PROGRESS")){
            inProgress(pesanan);
        }
        else if (cekKataSama(command,"BUY")){
            buy(posisi, peta, &gadgetInventory, &money);
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
