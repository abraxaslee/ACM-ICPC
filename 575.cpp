//2012/03/30
//575.cpp
//Run time: 0.004

#include <stdio.h>
#include <string.h>
int main(){

	#ifndef ONLINE_JUDGE
	freopen("575.in", "r", stdin);
	freopen("575.out", "w", stdout);
	#endif

	int i;
	int skew[35];
	for(i=0; i<32; ++i)
		skew[i] = (1 << i) -1;

	char binary[50];
	int length, ans;
	while(gets(binary) != NULL){
		if(binary[0] == '0' && binary[1] == '\0') break;
		length = strlen(binary);
		for(ans=i=0; i<length; ++i)
			ans += skew[length-i] * (binary[i] - '0');
		printf("%d\n", ans);
	}
	return 0;
}
