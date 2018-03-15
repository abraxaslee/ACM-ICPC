//2012/04/01
//377.cpp
//Run time: 0.004

#include <stdio.h>

int hash[300];


int main(){

	#ifndef ONLINE_JUDGE
	freopen("377.in", "r", stdin);
	//freopen("377.out", "w", stdout);
	#endif

	hash['U'] = 1, hash['C'] = 2, hash['D'] = 3;

	int cmd, i, loop, cow, testCase;
	char buff[20];

	scanf("%d", &testCase); getchar();

	puts("COWCULATIONS OUTPUT");
	while(testCase--){
		int num1[8] = {}, num2[8] = {};
		num1[4] = hash[getchar()];
		num1[3] = hash[getchar()];
		num1[2] = hash[getchar()];
		num1[1] = hash[getchar()];
		num1[0] = hash[getchar()];
		getchar();

		num2[4] = hash[getchar()];
		num2[3] = hash[getchar()];
		num2[2] = hash[getchar()];
		num2[1] = hash[getchar()];
		num2[0] = hash[getchar()];
		getchar();

		for(loop = 0; loop < 3; ++loop){
			cmd = getchar(); getchar();

			switch(cmd){
				case 'A':
					for(i=0; i<8; ++i){
						num2[i] += num1[i];
						if(num2[i] > 3)
							num2[i+1] += 1, num2[i] -= 4;
					}
					break;

				case 'L':
					for(i=7; i>0; --i)
						num2[i] = num2[i-1];

					num2[0] = 0;
					break;

				case 'R':
					for(i=0; i<7; ++i)
						num2[i] = num2[i+1];

					num2[7] = 0;
					break;

			}
		}
		cow = 1;
		for(i=7; i>=0; --i)
			if( hash[getchar()] != num2[i])
				cow = 0;
		if(testCase) getchar();
		if(cow) puts("YES");
		else puts("NO");
	}
	puts("END OF OUTPUT");
	return 0;
}
