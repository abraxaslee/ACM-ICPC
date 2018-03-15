//q10424.cpp - 2011/10/01
//accepted at 2011-10-01 09:53:44
//run time = 0.008
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10424.in", "r", stdin);
	freopen("q10424.out", "w", stdout);
	#endif


	while(true){
		int nameA = 0, nameB = 0;
		char c;

		while((c=getchar())!='\n'&& c > 0){
			if(c>=65&&c<=90){
					c = c - 64;
					nameA += c;
			}else if(c>=97&&c<=122){
					c = c - 96;
					nameA += c;
			}
		}

		if ( c <= 0 ){
			break;
		}

		while((c=getchar())!='\n'){
			if(c>=65&&c<=90){
					c = c - 64;
					nameB += c;
			}else if(c>=97&&c<=122){
					c = c - 96;
					nameB += c;
			}
		}
		while(nameA>=10){
			nameA = nameA%10 + nameA/10;
		}
		while(nameB>=10){
			nameB = nameB%10 + nameB/10;
		}
		if(nameA>=nameB){
			printf("%.2f %%\n", (double)(nameB) / nameA *100);
		}else{
			printf("%.2f %%\n", (double)(nameA) / nameB *100);
		}
	}

	return 0;
}
