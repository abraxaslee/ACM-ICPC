//q637.cpp - 2011/10/12
//accepted at 
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q637.in", "r", stdin);
	freopen("q637.out", "w", stdout);
	#endif

	int totalPages;
	while(scanf("%d", &totalPages)!=EOF && totalPages>0){
		int cap = 1;
		int front[25][2] = {}, back[25][2] = {};
		while(totalPages>cap*4){
			cap += 1;
		}
		int halfPages = totalPages / 2;
		bool frontPage = true;
		int i = 1;
		for(int j = 0;j < cap &&i<=totalPages;i++){
			if(frontPage){
				front[j][1] = i;
				frontPage = false;
			}else{
				back[j][0] = i;
				frontPage = true;
				j+= 1;
			}
		}
		frontPage = false;
		for(int j = cap-1;j >= 0 && i<=totalPages;i++){
			if(frontPage){
				front[j][0] = i;
				frontPage = false;
				j-= 1;
			}else{
				back[j][1] = i;
				frontPage = true;
			}
		}
		printf("Printing order for %d pages:\n", totalPages);
		for(int z=0;z<cap;z++){
			printf("Sheet %d, front: ", z+1);

				if(front[z][0]>0){
					printf("%d", front[z][0]);
				}else{
					printf("Blank");
				}

				if(front[z][1]>0){
					printf(", %d\n", front[z][1]);
				}else{
					printf(", Blank\n");
				}
			if(back[z][0]==0 && back[z][1]==0){
				break;
			}
			printf("Sheet %d, back : ", z+1);

				if(back[z][0]>0){
					printf("%d", back[z][0]);
				}else{
					printf("Blank");
				}

				if(back[z][1]>0){
					printf(", %d\n", back[z][1]);
				}else{
					printf(", Blank\n");
				}
		}
	}
	return 0;
}
