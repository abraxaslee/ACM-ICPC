//0.004
#include <stdio.h>

int main(){
	int m[13];
	m[0] = 2;
	m[1] = 7;
	m[2] = 5;
	m[3] = 30;
	m[4] = 169;
	m[5] = 441;
	m[6] = 1872;
	m[7] = 7632;
	m[8] = 1740;
	m[9] = 93313;
	m[10] = 459901;
	m[11] = 1358657;
	m[12] = 2504881;
	
	int k;
	while(1){
		scanf("%d", &k);
		if(k==0){
			break;
		}
		printf("%d\n", m[k-1]);
	}
	return 0;
}
