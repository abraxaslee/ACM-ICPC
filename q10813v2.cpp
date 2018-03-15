//Q10813 - Traditional BINGO
//accepted at 2011-09-01 06:54:33
//run time = 0.008
#include <stdio.h>
using namespace std;

inline void tickItOut(int);
inline bool matchItOut(void);
int bingoCard[5][5];
bool bingoPlace[5][5];
int i_count[5];
int j_count[5];
int caseNums = 0;

int main(){
	int luckyNum = 0;
	int tLuckyNum = 0;
	bool flagWinner = false;
	int currentCase = 0;
	scanf("%d",&caseNums);
		while(currentCase<caseNums){
			for(int i=0;i<5;i++){
				i_count[i] = 0;
				j_count[i] = 0;
				for(int j=0;j<5;j++){
					bingoCard[i][j] = 0;
					bingoPlace[i][j] = false;
				}
			}
			bingoPlace[2][2] = true;
			i_count[2] = 1;
			j_count[2] = 1;
			flagWinner = false;
			tLuckyNum = 0;
			for(int i=0;i<5;i++){
				if(i==2){
					scanf("%d %d %d %d", &bingoCard[i][0], &bingoCard[i][1], &bingoCard[i][3], &bingoCard[i][4],  &bingoCard[i][5]);
				}else{
					scanf("%d %d %d %d %d", &bingoCard[i][0], &bingoCard[i][1], &bingoCard[i][2], &bingoCard[i][3], &bingoCard[i][4],  &bingoCard[i][5]);
				}
			}
			while(tLuckyNum<75){
				scanf("%d", &luckyNum);
				tickItOut(luckyNum);
				tLuckyNum++;
				if(tLuckyNum>=4&&flagWinner==false){
					if(matchItOut()==true){
						printf("BINGO after %d numbers announced\n", tLuckyNum);
						flagWinner = true;
					}
				}
				if(flagWinner){
					break;
				}
			}
			while(tLuckyNum<75){
				scanf("%d", &luckyNum);
				tLuckyNum++;
			}
			currentCase++;
		}
	return 0;
}

inline void tickItOut(int luckyNum){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(bingoCard[i][j]==luckyNum){
				bingoPlace[i][j] = true;
				i_count[i]++;
				j_count[j]++;
				return;
			}
		}
	}
	return;
}

inline bool matchItOut(void){
	for(int i=0;i<5;i++){
			if(i_count[i] == 5||j_count[i]==5){
			return true;
		}
	}

	if(bingoPlace[0][0]&&bingoPlace[1][1]&&bingoPlace[2][2]&&bingoPlace[3][3]&&bingoPlace[4][4]){
		return true;
	}

	if(bingoPlace[4][0]&&bingoPlace[3][1]&&bingoPlace[2][2]&&bingoPlace[1][3]&&bingoPlace[0][4]){
		return true;
	}

	return false;
}
