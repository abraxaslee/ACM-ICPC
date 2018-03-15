//q10191.cpp - 2011/10/13
//accepted at 
//run time = 
#include <stdio.h>
using namespace std;

int works[100][4] = {}; //[i][0] = start hour, [1] start min, [2] end hour, [3] end min
int schedule[100] = {}; //using for index table
int top;

void insert(int j){
	int i;
	printf("insert : works[%d] = %d:%d\n", j, works[j][0], works[j][1]);
	for(i=top-1;i>=0&&works[schedule[i]][0]>=works[j][0];i--){ //check the indexed works is greater than input one( works)
		if(works[schedule[i]][0]==works[j][0]){ //if same hour, then compare minutes
			if(works[schedule[i]][1]<works[j][1]){
				break;
			}else{
				schedule[i+1] = schedule[i];
				continue;
			}
		}
		schedule[i+1] = schedule[i];
	}
	printf("insert at %d\n", i+1);
	schedule[i+1] = j;
	top += 1;
	for(int z=0;z<top;z++){
		printf("schedule[%d] = %d == works[%d][0] == %d == works[%d][1] == %d\n", z, schedule[z], schedule[z], works[schedule[z]][0], schedule[z], works[schedule[z]][1]);
	}
	putchar(10);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10191.in", "r", stdin);
	freopen("q10191.out", "w", stdout);
	#endif


	int totalWorks, currentCase = 0;
	while(scanf("%d", &totalWorks)!=EOF){
		getchar();
		top = 0;
		char s[300];

		//input working schedules ( hh:mm hh:mm  maybe not in order!!!) then sort them
		for(int i=0;i<totalWorks;i++){
			gets(s);
			sscanf(s, "%d:%d %d:%d", &works[i][0], &works[i][1], &works[i][2], &works[i][3]);
			insert(i);
		}
		printf("after sort :\n");
		for(int z=0;z<totalWorks;z++){
			printf("[%d]: %d:%d %d:%d\n", z , works[schedule[z]][0], works[schedule[z]][1], works[schedule[z]][2], works[schedule[z]][3]);
		}


		int lastTime = 600, nowTime, tmp;
		int goodHours = 10, goodMins = 0, longest = 0;
		int lastHours = 10, lastMins = 0;
		//everything start at 10:00
		if(totalWorks>0){
			longest = works[schedule[0]][0]*60 + works[schedule[0]][1] - 600;
		}
		for(int i=0;i<totalWorks;i++){
			tmp = schedule[i];
			nowTime = works[tmp][0] *60 + works[tmp][1];
			if(nowTime - lastTime > longest){
				longest = nowTime - lastTime;
				goodHours = lastHours;
				goodMins = lastMins;
			}
			lastTime = works[tmp][2] *60 + works[tmp][3];
			lastHours = works[tmp][2];
			lastMins = works[tmp][3];
		}

		//check any spare time till 18:00
		if(1080 - lastTime > longest){
			longest = 1080 - lastTime;
			if(totalWorks>0){
				goodHours = works[schedule[totalWorks-1]][2];
				goodMins = works[schedule[totalWorks-1]][3];
			}
		}
		if(longest<60){
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n", ++currentCase, goodHours, goodMins, longest);
		}else{
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n", ++currentCase, goodHours, goodMins, longest/60, longest%60);
		}
	}
	return 0;
}
