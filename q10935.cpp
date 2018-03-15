//q10935.cpp - 2011/10/10
//accepted at 
//run time = 0.016
#include <stdio.h>
#include <queue>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10935.in", "r", stdin);
	freopen("q10935.out", "w", stdout);
	#endif

	int n;
	while(scanf("%d", &n)!=EOF && n >0 ){

		//initizalize quque
		queue<int> cardQ;
		for(int i=1;i<=n;i++){
			cardQ.push(i);
		}

		printf("Discarded cards:");
		if(cardQ.size() >1){
			printf(" %d", cardQ.front()); cardQ.pop();
			cardQ.push(cardQ.front()); cardQ.pop();
		}

			while(cardQ.size() >= 2){
				printf(", %d", cardQ.front()); cardQ.pop();
				cardQ.push(cardQ.front()); cardQ.pop();
			}

			putchar(10);
		printf("Remaining card: %d\n", cardQ.front());
		cardQ.pop();
	}
	return 0;
}
