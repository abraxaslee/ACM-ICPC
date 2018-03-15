//q10903.cpp - 2011/09/14
//Q10903: Rock-Paper-Scissors
//accepted at 2011-09-24 13:45:11
//run time = 0.200
#include <stdio.h>
using namespace std;

struct player{
	int win;
	int lose;
};

int main(){
	bool once = false;
	int numPlayer, warPerPlayer; // numPlayer == n, totalWar == k
	caseStart:
	scanf("%d", &numPlayer);
	if(numPlayer == 0){
		return 0;
	}
	scanf("%d", &warPerPlayer);
	int totalWar = warPerPlayer * (numPlayer) * (numPlayer-1) / 2;

	struct player p[100] = {0,0};

	while(totalWar-- >0){
		int pA,pB;
		char handA[10], handB[10];
		scanf("%d %s %d %s", &pA, handA, &pB, handB);


		//r - rock , p - paper , s -  scissors
		if(handA[0] == 'r'){

			if(handB[0]=='s'){
				p[pA-1].win += 1;
				p[pB-1].lose += 1;
			}else if(handB[0]=='p'){
				p[pB-1].win += 1;
				p[pA-1].lose += 1;
			}else{
				continue;
			}

		}else if(handA[0] == 's'){

			if(handB[0] == 'p'){
				p[pA-1].win += 1;
				p[pB-1].lose += 1;
			}else if(handB[0] == 'r'){
				p[pB-1].win += 1;
				p[pA-1].lose += 1;
			}else{
				continue;
			}
		}else{

			if(handB[0] == 'r'){
				p[pA-1].win += 1;
				p[pB-1].lose += 1;
			}else if(handB[0] == 's'){
				p[pB-1].win += 1;
				p[pA-1].lose += 1;
			}else{
				continue;
			}

		}

	}
	if(once){
		printf("\n");
	}
	for(int i=0;i<numPlayer;i++){
		if(p[i].win+p[i].lose==0){
			printf("-\n");
		}else{
			printf("%.3f\n", (double)p[i].win/(p[i].win+p[i].lose));
		}
	}
	once = true;
	goto caseStart;
	return 0;
}
