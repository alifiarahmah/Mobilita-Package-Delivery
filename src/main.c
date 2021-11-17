#include <stdio.h>
#include<stdlib.h>

#include "commands/commands.h"
#include "modules/adt.h"
#include "main_menu.h"
#include "read_file.h"

#if defined(__WIN32) || defined(__WIN64) // Powershell
    #define clearscreen system("cls")
#else // Bash
    #define clearscreen system("clear")
#endif

// TO DO: efek & reward dari Heavy item dan perishable item

/* Proses: iterasi elemen di inprogress dan tas, dan menghapus semua item yang sudah perish */
/* I.S. Terdefinisi */
/* F.S. Jika time-TIME() elemen dari list lebih dari PTIME, elemen terhapus */
/*      Item di-pop dari tas */
// TODO: pindahin entah ke mana
void perishExpiredItem(int time, LList *inprogress, Stack *tas){
    Pesanan val;
    int i = 0;
    Address p = *inprogress; // iterasi inprogress
    while(p != NULL){
        if(time - TIME(INFO(p)) > PTIME(INFO(p))){ // item lebih lama di tas daripada perish timenya
            deleteAt(inprogress, i, &val);
            deleteIdxTas(tas, i, &val);
        } else {
            p = NEXT(p);
            i++;
        }
    }
}

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
    int VIP = 0; // efek dari pesanan VIP
    int psnBerhasil = 0; //jumlah pesanan yang berhasil diantarkan

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
        clearscreen;

        if (cekKataSama(command,"MOVE")){
            move(adj,&posisi,&time,lBuilding,&incTime,saveTime,&timeSpeed);

            // tiap pindah waktu, pindahin pesanan dari queue pesanan ke linkedlist todo
            int i = 0;
            while(TIME(HEAD(pesanan)) == time){
                if (TYPE(ITEM(HEAD(pesanan))) == 'V') {
                    VIP++;
                }
                dequeue(&pesanan, &val);
                insertLastLL(&todo, val);
                i++;
            }

            if (i != 0){
                printf("%d pesanan baru masuk!",i);
            }

            // tiap pindah waktu, item yang lewat time limit perish
            // perishExpiredItem(time, &inprogress, &tas);

        }
        else if (cekKataSama(command,"PICK_UP")){
            pickUp(posisi, peta, &todo, &inprogress, &tas, &incTime, &timeSpeed, VIP);
        }
        else if (cekKataSama(command,"DROP_OFF")){
            dropOff(&tas,&inprogress,posisi,&money,&output,&incTime,&timeSpeed,&canReturn,&VIP,&psnBerhasil);
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
        else if ((isEmpty(pesanan)) && (isEmptyLL(todo)) && (isEmptyLL(inprogress)) && (isEmptyStack(tas)) && (Name(posisi) == '8')){
            printf("TERIMA KASIH SUDAH BERMAIN\n");
            printf("Semua pesanan berhasil dikirim.\n");
            break;
        }
        else{
            printf("Masukan command tidak valid, coba lagi!");
        }
    }while(!cekKataSama(command,"EXIT"));
    
    printf("-------------Statistik Akhir-------------");
    printf("Jumlah pesanan yang berhasil diantar: %d\n",psnBerhasil);
    printf("Waktu yang terlampaui: %d\n",time);

    exit(0);
}
