//q11222.cpp - 2012/01/06
//accepted at 
//run time = 0.008
#include <stdio.h>

int solved[3][10001];
int top[3];

int max(int A, int B){
	return A>B?A:B;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11222.in", "r", stdin);
	freopen("q11222.out", "w", stdout);
	#endif

	int caseNum, n, z, tmp, sum, highest, current = 0;
	scanf("%d",&caseNum);
	while(caseNum--){
		top[0] = top[1] = top[2] = sum = 0;
		int AC[10001] = {};
		scanf("%d", &n);
		sum += n;
		while(n--){
			scanf("%d", &tmp);
			AC[tmp]++;
		}

		scanf("%d", &n);
		sum += n;
		while(n--){
			scanf("%d", &tmp);
			AC[tmp] += 2;
		}

		scanf("%d", &n);
		sum += n;
		while(n--){
			scanf("%d", &tmp);
			AC[tmp] += 4;
		}


		for(n=0; sum > 0; ++n){
			if(AC[n] == 0) continue;
			switch(AC[n]){
				case 1:
					solved[0][top[0]++] = n;
					sum--;
					break;
				case 2:
					solved[1][top[1]++] = n;
					sum--;
					break;
				case 4:
					solved[2][top[2]++] = n;
					sum--;
					break;
				case 3:
				case 5:
				case 6:
					sum -= 2;
					break;
				case 7:
					sum -= 3;
					break;
			}

		}
		highest = max(top[0], max(top[1], top[2]));
		printf("Case #%d:\n", ++current);
		for(n=0; n<3; ++n){
			if(top[n] == highest){
				printf("%d %d", n+1, top[n]);
				for(z=0; z<top[n]; ++z)
					printf(" %d", solved[n][z]);
				putchar(10);
			}
		}
	}
	return 0;
}
