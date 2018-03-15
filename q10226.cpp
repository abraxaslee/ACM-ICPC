//q10226v2.cpp - 2012/01/06
//accepted at 
//run time = 1.276
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

char buff[50];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10226.in", "r", stdin);
	freopen("q10226.out", "w", stdout);
	#endif

	int caseNum, sums, once = 0;
	double percentages;
	scanf("%d", &caseNum); 	getchar(); getchar();
	while(caseNum--){
		map<string, int> forest;
		sums = 0;
		while(gets(buff)!=NULL){
			if(buff[0] == '\0')		break;
			forest[buff]++;
			sums++;
		}

		percentages = 100.0 / sums;
		if(once)		putchar(10);
		for(map<string, int>::iterator iter = forest.begin(); iter != forest.end(); iter++){
			cout << iter->first;
			printf(" %.4lf\n", iter->second * percentages);
		}

		once = 1;
	}
	return 0;
}
