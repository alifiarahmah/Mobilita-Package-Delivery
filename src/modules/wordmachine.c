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

Word stringToWord (char arr[]){
/* Mengubah input string menjadi type Word*/
	int i = 0;
	Word kata;
	while (arr[i] != '\0'){
		kata.contents[i] = arr[i];
		i++;
	}
	kata.contents[i] = '\0';
	kata.length = i;
	return kata;
}

Word concatKata (char arr1[], char arr2[]){
/* Menggabungkan 2 string menjadi 1 Word */
	int i,j = 0;
	Word kata1,kata2,kata3;
	kata1 = stringToWord(arr1);
	kata2 = stringToWord(arr2);
	i = 0;
	while (i<kata1.length){
		kata3.contents[j] = kata1.contents[i];
		i++;
		j++;
	}
	kata3.length = kata1.length;
	i = 0;
	while (i<kata2.length){
		kata3.contents[j] = kata2.contents[i];
		i++;
		j++;
	}
	kata3.contents[j] = '\0';
	kata3.length += kata2.length;
	return kata3;
}

boolean cekKataSama(char arr1[], char arr2[]){
/* Memeriksa apakah kedua string yang dimasukkan sama atau tidak*/
	int i = 0;
	Word kata1,kata2;
	boolean sama = true;
	kata1 = stringToWord(arr1);
	kata2 = stringToWord(arr2);
	if (kata1.length == kata2.length){
		while ((sama == true) && (i<kata1.length)){
			if (kata1.contents[i] != kata2.contents[i]){
				sama = false;
			}
			i++;
		}
	}
	else{
		sama = false;
	}
	return sama;	
}

#endif

