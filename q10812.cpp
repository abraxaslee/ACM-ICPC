//Q10812: Beat the Spread!
//accepted at 2011-08-30 10:48:16
//run time = 0.008

#include <stdio.h>
using namespace std;

int main(){
	int caseNum;
	unsigned int x, y, temp;
	while(scanf("%d", &caseNum)!=EOF){
		while(caseNum>0){
			scanf("%d %d", &x, &y);
			temp = x+y;
			if(x>=y){
				if(temp%2 ==0){
					temp /= 2;
					printf("%d %d\n", temp, temp-y);
				}else{
					printf("impossible\n");
				}
			}else{
				printf("impossible\n");
			}
		caseNum--;
		}
	}
	return 0;
}
