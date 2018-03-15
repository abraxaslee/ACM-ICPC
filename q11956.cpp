//q11956.cpp - 2011/10/09
//accepted at 
//run time = 0.236
#include <stdio.h>
using namespace std;

int main(){

	int caseNum, currentCase = 0;
	scanf("%d\n", &caseNum);
	while(caseNum-- > 0){
		currentCase += 1;
		unsigned char memory[101] = {};
		int ptr = 0;
		int c;
		while((c=getchar())!=EOF&&c!=10){
			switch(c){
				case '.':
					break;
				case '+':
					memory[ptr] += 1;
					break;
				case '-':
					memory[ptr] -= 1;
					break;
				case '>':
					ptr = (ptr + 1) % 100;
					break;
				case '<':
					if(ptr==0){
						ptr = 99;
						break;
					}
					ptr = ptr - 1;
					break;
			}
		}
		printf("Case %d:", currentCase);
		for(int i=0;i<100;i++){
			printf(" %02X", memory[i]);
		}
		putchar(10);
	}
	return 0;
}
