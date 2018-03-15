//q492.cpp - 2011/09/18
//accepted at 
//run time = 
#include <cstdio>
#include <cctype>
using namespace std;

bool isVowel(char ch){
	switch(ch){
	case 'A':
	case 'a':
	case 'E':
	case 'e':
	case 'I':
	case 'i':
	case 'O':
	case 'o':
	case 'U':
	case 'u':
		return true;
	default:
		return false;
	}
}

int main(){
	char myBuffer[4096];
	int bufferIndex = 0;
	char c;
	bool isWord = false;
	while((c=getchar())!=EOF){
		switch(isWord){

			case false:
				if(isalpha(c)){
					bufferIndex = 0;
					myBuffer[bufferIndex++] = c;
					isWord = true;
				}else{
					putchar(c);
				}
				break;

			case true:
				if(isalpha(c)){
					myBuffer[bufferIndex++] = c;
				}else{
					if(isVowel(myBuffer[0])){
						myBuffer[bufferIndex] = '\0';
						printf(myBuffer);
						printf("ay");
					}else{
						myBuffer[bufferIndex] = '\0';
						printf(myBuffer+1);
						putchar(myBuffer[0]);
						printf("ay");
					}
					putchar(c);
					isWord = false;
				}
				break;
		}
	}
	return 0;
}
