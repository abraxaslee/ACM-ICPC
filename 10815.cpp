//2012/02/26
//10815.cpp
//Run time: 0.028

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int i;
void lower(char *target){
	for(i=0; target[i] !='\0'; ++i)
		if(target[i] > 64 & target[i] < 91)
			target[i] += 32;
}

char buff[300];
int main(){

	#ifndef ONLINE_JUDGE
	freopen("10815.in", "r", stdin);
	freopen("10815.out", "w", stdout);
	#endif

	map<string, bool> dictionary;
	char *token;
	while(gets(buff)!=NULL){
		for(token = strtok(buff, " !\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~\t\r\n");
		token != NULL;
		token = strtok(NULL, " !\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~\t\r\n")){
			lower(token);
			dictionary[token] = true;
		}
	}
	map<string, bool>::iterator iter;
	for(iter = dictionary.begin(); iter != dictionary.end(); ++iter)
		cout << iter->first << "\n";
	return 0;
}
