/*
	NIM : 13520122
	Nama : Alifia Rahmah
	Tanggal : 24/09/2021
	Topik praktikum : Mesin Kata
	Deskripsi : Pra-Praktikum 6 - wordmachine.c
*/

/* Definisi Word Engine */

#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include "boolean.h"
#include "charmachine.h"

#define CAPACITY 50
#define BLANK ' '

typedef struct {
   char contents[CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Word;

/* Word Engine State */
boolean endWord;
Word currentWord;

/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
void ignoreBlank(){
	while(currentChar == BLANK){
		adv();
	}
}

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
void copyWord(){
	int i = 0;
	while ((currentChar != MARK) && (currentChar != BLANK) && (i < CAPACITY)){
		currentWord.contents[i] = currentChar;
		adv();
		i++;
	}
	currentWord.length = i;
	ignoreBlank();
}
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void startWord(){
	start();
	ignoreBlank();
	if (currentChar == MARK){
		endWord = true;
	} else {
		endWord = false;
		copyWord();
	}
}

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
void advWord(){
	ignoreBlank();
	if (currentChar == MARK){
		endWord = true;
	} else {
		copyWord();
	}
}

#endif

