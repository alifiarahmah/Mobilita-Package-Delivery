#include <stdio.h>
#include "modules/wordmachine.h"

int main(){
	// TODO: ganti hehe
	startWord();
	while (!endWord){
		printf("%s\n", currentWord.contents);
		advWord();
	}
	return 0;
}