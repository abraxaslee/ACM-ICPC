//q12019.cpp - 2011/10/24
//accepted at 
//run time = 
#include <stdio.h>

int calendar[12][31];
char weekday[7][20] = {
		{'M','o','n','d','a','y','\0'},
		{'T','u','e','s','d','a','y','\0'},
		{'W','e','d','n','e','s','d','a','y','\0'},
		{'T','h','u','r','s','d','a','y','\0'},
		{'F','r','i','d','a','y','\0'},
		{'S','a','t','u','r','d','a','y','\0'},
		{'S','u','n','d','a','y','\0'}
};


void build(){
	int m, day = 5;
	for(int i=0;i<12;i++){
		if(i==1)
			m=28;
		else if(i==0||i==2||i==4||i==6||i==7||i==9||i==11)
			m=31;
		else
			m=30;

		for(int j=0;j<m;j++,day=(day+1)%7){
			calendar[i][j] = day;
		}
	}

	return;
}


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q12019.in", "r", stdin);
	freopen("q12019.out", "w", stdout);
	#endif
	build();
	int caseNum, mm, dd;
	scanf("%d", &caseNum);
	while(caseNum--){

		scanf("%d%d", &mm , &dd);
		puts(weekday[calendar[mm-1][dd-1]]);

	}
	return 0;
}
