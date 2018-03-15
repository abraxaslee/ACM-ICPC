//q10038.cpp - 2011/09/05
//10038 - Jolly Jumpers
//accepted at 2011-09-05 06:28:28
//run time = 0.012
#include <stdio.h>
using namespace std;

int main(){
	int n = 0;
	long int temp = 0;
	bool flagJ = true;
	while(scanf("%d", &n)!=EOF){

		int i = 0;
		int *num = new int[n];
		bool *seen = new bool[n];
		flagJ = true;
		for(int j=0;j<n;j++){
			seen[j] = false;
		}

		scanf("%d", &num[0]);
		for(i=1;i<n&&flagJ;i++){
			scanf("%d", &num[i]);
			temp = num[i] - num[i-1];
			if(temp<0){ temp = -temp;}
			if(1>temp||temp>n-1){
				flagJ=false;break;
			}else{
				if(seen[temp]){flagJ=false;break;}
				seen[temp] = true;
			}
		}
		//discard
		if(flagJ){
			for(int j=1;j<n;j++){
				if(!seen[j]){
						flagJ = false;
						break;
				}

			}
		}else{
			while(i<n-1){
					scanf("%d", &num[i]);
					i = i+1;
			}
		}

		if(flagJ){
			printf("Jolly\n");
		}else{
			printf("Not jolly\n");
		}

		delete [] num;
		delete [] seen;
	}
	return 0;
}
