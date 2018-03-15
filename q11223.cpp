//q11223.cpp - 2011/12/17
//accepted at
//run time = 0.012
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

char buff[2005];
map<string, int> Morse;
map<string, int>::iterator iter;

void build_morse(){
	Morse.insert(pair<string, int>(".-", 'A'));
	Morse.insert(pair<string, int>("-...", 'B'));
	Morse.insert(pair<string, int>("-.-.", 'C'));
	Morse.insert(pair<string, int>("-..", 'D'));
	Morse.insert(pair<string, int>(".", 'E'));
	Morse.insert(pair<string, int>("..-.", 'F'));
	Morse.insert(pair<string, int>("--.", 'G'));
	Morse.insert(pair<string, int>("....", 'H'));
	Morse.insert(pair<string, int>("..", 'I'));
	Morse.insert(pair<string, int>(".---", 'J'));
	Morse.insert(pair<string, int>("-.-", 'K'));
	Morse.insert(pair<string, int>(".-..", 'L'));
	Morse.insert(pair<string, int>("--", 'M'));
	Morse.insert(pair<string, int>("-.", 'N'));
	Morse.insert(pair<string, int>("---", 'O'));
	Morse.insert(pair<string, int>(".--.", 'P'));
	Morse.insert(pair<string, int>("--.-", 'Q'));
	Morse.insert(pair<string, int>(".-.", 'R'));
	Morse.insert(pair<string, int>("...", 'S'));
	Morse.insert(pair<string, int>("-", 'T'));
	Morse.insert(pair<string, int>("..-", 'U'));
	Morse.insert(pair<string, int>("...-", 'V'));
	Morse.insert(pair<string, int>(".--", 'W'));
	Morse.insert(pair<string, int>("-..-", 'X'));
	Morse.insert(pair<string, int>("-.--", 'Y'));
	Morse.insert(pair<string, int>("--..", 'Z'));
	Morse.insert(pair<string, int>("-----", '0'));
	Morse.insert(pair<string, int>(".----", '1'));
	Morse.insert(pair<string, int>("..---", '2'));
	Morse.insert(pair<string, int>("...--", '3'));
	Morse.insert(pair<string, int>("....-", '4'));
	Morse.insert(pair<string, int>(".....", '5'));
	Morse.insert(pair<string, int>("-....", '6'));
	Morse.insert(pair<string, int>("--...", '7'));
	Morse.insert(pair<string, int>("---..", '8'));
	Morse.insert(pair<string, int>("----.", '9'));
	Morse.insert(pair<string, int>(".-.-.-", '.'));
	Morse.insert(pair<string, int>("--..--", ','));
	Morse.insert(pair<string, int>("..--..", '?'));
	Morse.insert(pair<string, int>(".----.", '\''));
	Morse.insert(pair<string, int>("-.-.--", '!'));
	Morse.insert(pair<string, int>("-..-.", '/'));
	Morse.insert(pair<string, int>("-.--.", '('));
	Morse.insert(pair<string, int>("-.--.-", ')'));
	Morse.insert(pair<string, int>(".-...", '&'));
	Morse.insert(pair<string, int>("---...", ':'));
	Morse.insert(pair<string, int>("-.-.-.", ';'));
	Morse.insert(pair<string, int>("-...-", '='));
	Morse.insert(pair<string, int>(".-.-.", '+'));
	Morse.insert(pair<string, int>("-....-", '-'));
	Morse.insert(pair<string, int>("..--.-", '_'));
	Morse.insert(pair<string, int>(".-..-.", '"'));
	Morse.insert(pair<string, int>(".--.-.", '@'));
	return;
}

void solve(){
	char pass[20] = {};
	int i, top;
	for(i = top = 0;buff[i] != '\0';++i){
		if(buff[i] != ' ')
			pass[top++] = buff[i];
		else{
			pass[top] = '\0';
			if(top){
				iter = Morse.find(pass);
				putchar((*iter).second);
				top = 0;
			}
			if(buff[i+1] == ' '){
				putchar(32);
				i++;
			}
		}
	}
	if(top){
		pass[top] = '\0';
		iter = Morse.find(pass);
		putchar((*iter).second);
	}
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11223.in", "r", stdin);
	freopen("q11223.out", "w", stdout);
	#endif

	build_morse();
	int caseNum, current = 0;
	scanf("%d", &caseNum); getchar();
	while(caseNum--){
		gets(buff);
		if(current)	putchar(10);
		printf("Message #%d\n", ++current);
		solve();
		putchar(10);
	}
	return 0;
}
