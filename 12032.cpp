//2012/02/18
//12032.cpp
//Run time: 0.080

#include <stdio.h>

int interval[100005];
int top, current, maxi;

int solve(){
	int i;
	for(i=0; i<top; ++i)
		if(interval[i] == maxi)
			--maxi;
		else if(interval[i] > maxi )
			return 1;
	return 0;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("12032.in", "r", stdin);
	freopen("12032.out", "w", stdout);
	#endif

	int testCase, i, temp, prev, ans;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d", &top);

		for(maxi=prev=i=0; i<top; ++i){
			scanf("%d", &temp);
			interval[i] = temp - prev;
			prev = temp;
			if(interval[i] > maxi) maxi = interval[i];
		}

		ans = maxi;

		printf("Case %d: %d\n", ++current, ans + solve());

	}
	return 0;
}
