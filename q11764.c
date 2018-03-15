//0.004
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11764.in", "r", stdin);
	freopen("q11764.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0;
	int wallNum, highJump, lowJump, wall, wallLast;
	scanf("%d", &caseNum);
	while(caseNum-- > 0){
		scanf("%d", &wallNum);
		highJump = 0; lowJump = 0;
		wallLast = 0;

		scanf("%d", &wall);
		wallNum -= 1;
		while(wallNum-- >0){
			wallLast = wall;
			scanf("%d", &wall);
			if(wallLast < wall){
				highJump += 1;
			}else if(wallLast >wall){
				lowJump += 1;
			}
		}
		printf("Case %d: %d %d\n", ++currentCase, highJump, lowJump);
	}
	return 0;
}
