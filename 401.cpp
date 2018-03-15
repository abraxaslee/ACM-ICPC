//2012/02/18
//401.cpp
//Run time: 0.008

#include <stdio.h>
#include <string.h>
int reverse[300];
char string[1000];
int top, half, i, j, ans;

int isPlaindrome(){
	for(i=0, j=top-1; i<half; --j, ++i)
		if(string[i] != string[j])
			return 0;
	return 1;
}

int isMirrored(){
	for(i=0, j=top-1; i<half; --j, ++i)
		if(string[i] != reverse[string[j]] && reverse[string[i]] != string[j])
			return 0;
	if(top & 1)
		if(string[half] != reverse[string[half]])
			return 0;
	return 2;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("401.in", "r", stdin);
	freopen("401.out", "w", stdout);
	#endif

	reverse['A'] = 'A';
	reverse['E'] = '3';
	reverse['H'] = 'H';
	reverse['I'] = 'I';
	reverse['J'] = 'L';
	reverse['L'] = 'J';
	reverse['M'] = 'M';
	reverse['O'] = 'O';
	reverse['S'] = '2';
	reverse['T'] = 'T';
	reverse['U'] = 'U';
	reverse['V'] = 'V';
	reverse['W'] = 'W';
	reverse['X'] = 'X';
	reverse['Y'] = 'Y';
	reverse['Z'] = '5';
	reverse['1'] = '1';
	reverse['2'] = 'S';
	reverse['3'] = 'E';
	reverse['5'] = 'Z';
	reverse['8'] = '8';


	while( gets(string) != NULL ){
		if(string[0] == '\0')	continue;
		top = strlen(string);
		half = top/2;

		switch(isPlaindrome() + isMirrored()){
			case 0:
				printf("%s -- is not a palindrome.\n\n", string);
				break;
			case 1:
				printf("%s -- is a regular palindrome.\n\n", string);
				break;
			case 2:
				printf("%s -- is a mirrored string.\n\n", string);
				break;
			case 3:
				printf("%s -- is a mirrored palindrome.\n\n", string);
				break;
		}
	}
	return 0;
}
