//q11219.cpp - 2011/11/03
//accepted at 
//run time = 0.008 c
#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11219.in", "r", stdin);
	freopen("q11219.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0;
	scanf("%d", &caseNum);

	struct DATE{
		int dd; int mm; int yy;
	} today, birth;

	int age;
	while(caseNum--){
		age = 0;
		scanf("%d/%d/%d", &today.dd, &today.mm, &today.yy);
		scanf("%d/%d/%d", &birth.dd, &birth.mm, &birth.yy);

		printf("Case #%d: ", ++currentCase);
		if(today.yy == birth.yy){
			if(today.mm < birth.mm){
				puts("Invalid birth date");
				continue;
			}else if(today.mm == birth.mm && today.dd < birth.dd){
				puts("Invalid birth date");
				continue;
			}
		}
		age = today.yy - birth.yy;
		if(today.mm < birth.mm){
			age -= 1;
		}else if(today.mm == birth.mm && today.dd < birth.dd){
			age -= 1;
		}
		if(age < 0){
			puts("Invalid birth date");
			continue;
		}
		if(age>130){
			puts("Check birth date");
		}else{
			printf("%d\n", age);
		}
	}
	return 0;
}

