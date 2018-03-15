// 0.004
#include <stdio.h>

int main(){
	char inputChar;
	int flagA=0;
	while((inputChar=getchar())!= EOF){
		if(inputChar == -1){return 0;}
		if(inputChar != 34){
			putchar(inputChar);
		}else{
			if(flagA == 1){
				putchar(39);
				putchar(39);
				flagA = 0;
			}else{
				putchar(96);
				putchar(96);
				flagA = 1;
			}

		}
	}
	return 0;
}
