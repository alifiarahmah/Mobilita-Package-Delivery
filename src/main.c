#include <stdio.h>

#include "commands/commands.h"
#include "modules/adt.h"
#include "main_menu.h"
#include "read_file.h"

// TO DO: efek & reward dari Heavy item dan perishable item

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
    char output;

    int money = 0; // uang Mobita
    int time = 0; // waktu berjalan
    int incTime = 1; // skala penambahan waktu
    int saveTime = 0; // tempat penyimpan waktu sebelum ability
    int timeSpeed = 0; // menyimpan ability Speed Boost
    boolean canReturn = false; // kondisi apakah Mobita bisa return

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
            move(adj,&posisi,&time,lBuilding,&incTime,saveTime,&timeSpeed);

            // tiap pindah waktu, pindahin pesanan dari queue pesanan ke linkedlist todo
            int i = 0;
            while(TIME(HEAD(pesanan)) == time){
                dequeue(&pesanan, &val);
                insertLastLL(&todo, val);
                i++;
            }

            if (i != 0){
                printf("%d pesanan baru masuk!",i);
            }

            // tiap pindah waktu, item yang lewat time limit perish
            // perishExpiredItem(&time, &inprogress, &tas);

        }
        else if (cekKataSama(command,"PICK_UP")){
            pickUp(posisi, peta, &todo, &inprogress, &tas, &incTime, &timeSpeed);
        }
        else if (cekKataSama(command,"DROP_OFF")){
            dropOff(&tas,&inprogress,posisi,&money,&output,&incTime,&timeSpeed);
        }
        else if (cekKataSama(command,"MAP")){
            Map(adj,peta,posisi,todo,tas);
        }
        else if (cekKataSama(command,"TO_DO")){
            todolist(todo);
        }
        else if (cekKataSama(command,"IN_PROGRESS")){
            inProgress(inprogress);
        }
        else if (cekKataSama(command,"BUY")){
            buy(posisi, peta, &gadgetInventory, &money);
        }
        else if (cekKataSama(command,"INVENTORY")){
            inventory(&gadgetInventory,&time,&incTime,&saveTime,&tas);
            // TODO: tambah efek dari pemakaian tiap gadget
        }
        else if (cekKataSama(command,"HELP")){
            help(&canReturn);
        }
        else if (cekKataSama(command,"RETURN")){
            returnToSender(&inprogress, &todo, &tas, &canReturn);
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
