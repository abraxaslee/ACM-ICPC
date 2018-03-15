//q739.cpp - 2011/12/29
//accepted at 
//run time = 0.016
#include <stdio.h>

int hash[255];
char word[30];
char soundex[5];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q739.in", "r", stdin);
	freopen("q739.out", "w", stdout);
	#endif


	hash['B'] = hash['P'] = hash['F'] = hash['V'] = 1;
	hash['C'] = hash['S'] = hash['K'] = hash['G'] = hash['J'] = hash['Q'] = hash['X'] = hash['Z'] = 2;
	hash['D'] = hash['T'] = 3;
	hash['L'] = 4;
	hash['M'] = hash['N'] = 5;
	hash['R'] = 6;
	hash['A'] = hash['E'] = hash['I'] = hash['O'] = hash['U'] = hash['Y'] = hash['W'] = hash['H'] = -1;

	int last, i, j;

	puts("         NAME                     SOUNDEX CODE");
	while(gets(word)!=NULL){
		last = hash[word[0]];
		soundex[0] = word[0];
		soundex[1] = soundex[2] = soundex[3] = '0';
		soundex[5] = '\0';
		char output[50] = {"                                  "};
		output[9] = word[0];
		for(i=j=1; word[i] != '\0'; ++i){
			output[i+9] = word[i];
			if(hash[word[i]] == last)
				continue;
			if(hash[word[i]] <= 0)
				last = 0;
			else if(j<4){
				last = hash[word[i]];
				soundex[j++] = last +'0';
			}
		}
		printf("%s%s\n", output, soundex);

	}
	puts("                   END OF OUTPUT");
	return 0;
}
