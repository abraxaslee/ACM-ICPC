//2012/03/26
//340.cpp
//Run time: 0.008

#include <stdio.h>

int password[1005], answer[1005];
int length, caseNum;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("340.in", "r", stdin);
	freopen("340.out", "w", stdout);
	#endif

	int remain[10], A, B, i;

	while(scanf("%d", &length) == 1){
		if(length == 0)	break;

		int hash[10] = {};

		for(i=0; i<length; ++i)
			scanf("%d", &password[i]), hash[password[i]]++;

		printf("Game %d:\n", ++caseNum);

		while(1){

			A = B = 0;

			for(i=0; i<10; ++i)
				remain[i] = hash[i];

			int check = 0;
			for(i=0; i<length; ++i){
				scanf("%d", &answer[i]);
				check += answer[i];
				if(password[i] == answer[i])
					remain[answer[i]]--, ++A, answer[i] = 0;
			}

			if(check == 0)	break;

			for(i=0; i<length; ++i)
				if(remain[answer[i]] > 0)
					remain[answer[i]]--, B++;

			printf("    (%d,%d)\n", A, B);
		}

	}

	return 0;
}
