//q10371.cpp - 2011/12/23
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <string.h>

int getZoneTime(char name[]){
	if(name[3] == '\0'){
		if(strcmp(name, "GMT") == 0)
			return 0;
		if(strcmp(name, "BST") == 0)
			return 60;
		if(strcmp(name, "IST") == 0)
			return 60;
		if(strcmp(name, "WET") == 0)
			return 0;
		if(strcmp(name, "CET") == 0)
			return 60;
		if(strcmp(name, "EET") == 0)
			return 120;
		if(strcmp(name, "MSK") == 0)
			return 180;
		if(strcmp(name, "MSD") == 0)
			return 240;
		if(strcmp(name, "AST") == 0)
			return -240;
		if(strcmp(name, "ADT") == 0)
			return -180;
		if(strcmp(name, "NST") == 0)
			return -210;
		if(strcmp(name, "NDT") == 0)
			return -150;
		if(strcmp(name, "EST") == 0)
			return -300;
		if(strcmp(name, "EDT") == 0)
			return -240;
		if(strcmp(name, "CST") == 0)
			return -360;
		if(strcmp(name, "CDT") == 0)
			return -300;
		if(strcmp(name, "MST") == 0)
			return -420;
		if(strcmp(name, "MDT") == 0)
			return -360;
		if(strcmp(name, "PST") == 0)
			return -480;
		if(strcmp(name, "PDT") == 0)
			return -420;
		if(strcmp(name, "HST") == 0)
			return -600;
	}else{
		if(strcmp(name, "WEST") == 0)
			return 60;
		if(strcmp(name, "CEST") == 0)
			return 120;
		if(strcmp(name, "EEST") == 0)
			return 180;
		if(strcmp(name, "AKST") == 0)
			return -540;
		if(strcmp(name, "AKDT") == 0)
			return -480;
		if(strcmp(name, "AEST") == 0)
			return 600;
		if(strcmp(name, "AEDT") == 0)
			return 660;
		if(strcmp(name, "ACST") == 0)
			return 570;
		if(strcmp(name, "ACDT") == 0)
			return 630;
		if(strcmp(name, "AWST") == 0)
			return 480;
	}
	return 0;
}

char buff[35];
char zone[2][5];
char timetag[5];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10371.in", "r", stdin);
	freopen("q10371.out", "w", stdout);
	#endif

	int caseNum, time, HH, MM;
	scanf("%d",&caseNum); getchar();
	while(caseNum--){
		gets(buff);

		if(buff[0] == 'n'){
			sscanf(buff, "%*s%s%s", zone[0], zone[1]);
			time = 720;
		}
		else if(buff[0] == 'm'){
			sscanf(buff, "%*s%s%s", zone[0], zone[1]);
			time = 1440;
		}else{
			sscanf(buff, "%d:%d%s%s%s", &HH, &MM, timetag, zone[0], zone[1]);
			time = HH*60 + MM;
			if(timetag[0] == 'p' && HH < 12)
				time += 720;
			if(timetag[0] == 'a' && HH == 12)
				time -= 720;
		}

		time = time - getZoneTime(zone[0]) + getZoneTime(zone[1]);

		if(time < 0)
			time += 1440;
		else
			time %= 1440;

		if(time == 720)
			puts("noon");
		else if(time == 0)
			puts("midnight");
		else{
			HH = time/60; 	MM = time%60;
			if(HH > 12)
				printf("%d:%02d p.m.\n", HH-12, MM);
			else if(HH == 12)
				printf("12:%02d p.m.\n", MM);
			else if(HH == 0)
				printf("12:%02d a.m.\n", MM);
			else
				printf("%d:%02d a.m.\n", HH, MM);
		}

	}

	return 0;
}
