// 0.004

#include <stdio.h>

int main(){

	int caseNum;
	scanf("%d", &caseNum);
	getchar();
	while(caseNum-- >0){
		char c[6] = {};
		int one[3] = {};
		gets(c);
		if(c[4]=='\0'){
			if(c[0]=='o'){
				one[0] = 1;
			}
			if(c[1]=='n'){
				one[1] = 1;
			}
			if(c[2]=='e'){
				one[2] = 1;
			}

			if( (one[0]+one[1]+one[2])>=2){
						putchar(49);
					}else{
						putchar(50);
					}

		}else{
			putchar(51);
		}
		putchar(10);
	}
	return 0;
}
