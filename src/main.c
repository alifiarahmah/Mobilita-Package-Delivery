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
    
    CreateQueue(&pesanan);
    MainMenu(&fileKonfig);
    bacaFile(fileKonfig,&peta,&adj,&pesanan,&lBuilding);
    do{
        printf("\n\n");
        printf("Mobita berada di posisi \n");
        /*print posisi*/
        printf("Waktu: \n");
        /*print waktu*/
        printf("Uang yang dimiliki: \n");
        /*print uang*/
        printf("ENTER COMMAND: ");
        scanf("%s",command);
        if (cekKataSama(command,"MOVE")){
            printf("MOVE");
        }
        else if (cekKataSama(command,"PICK_UP")){
            printf("PICK_UP");
        }
        else if (cekKataSama(command,"DROP_OFF")){
            printf("DROP_OFF");
        }
        else if (cekKataSama(command,"MAP")){
            printf("MAP");
        }
        else if (cekKataSama(command,"TO_DO")){
            printf("TO_DO");
        }
        else if (cekKataSama(command,"IN_PROGRESS")){
            printf("IN_PROGRESS");
        }
        else if (cekKataSama(command,"BUY")){
            printf("BUY");
        }
        else if (cekKataSama(command,"INVENTORY")){
            printf("INVENTORY");
        }
        else if (cekKataSama(command,"HELP")){
            printf("HELP");
        }
        else if (cekKataSama(command,"EXIT")){
            printf("End\n");
        }
        else{
            printf("Masukan command tidak valid, coba lagi!");
        }
    }while(!cekKataSama(command,"EXIT"));
    exit(0);
}
