//2012/03/16
//145.cpp
//Run time: 0.004

#include <stdio.h>

const double hash[5][3] =
{
	{0.10, 0.06, 0.02},
	{0.25, 0.15, 0.05},
	{0.53, 0.33, 0.13},
	{0.87, 0.47, 0.17},
	{1.44, 0.80, 0.30}
};

int main(){

	#ifndef ONLINE_JUDGE
	freopen("145.in", "r", stdin);
	freopen("145.out", "w", stdout);
	#endif

	int SHH, SMM, EHH, EMM, c;
	char bill[50], buff[1000], plan[3];
	int start, end, DAY, EVEN, NIGHT;
	double FEE;
	while(scanf("%s%s%d%d%d%d", plan, bill, &SHH, &SMM, &EHH, &EMM) == 6){

		FEE = 0;
		DAY = EVEN = NIGHT = 0;

		start = SHH * 60 + SMM, end = EHH * 60 + EMM;

		if(start>= 0 && start < 480){
			NIGHT = 600 - start;
			DAY = 600;
			EVEN = 240;
		}else if(start >= 480 && start < 1080){
			DAY = 1080 - start;
			EVEN = 240;
			NIGHT = 120;
		}else if(start >= 1080 && start < 1320){
			EVEN = 1320 - start;
			NIGHT = 120;
		}else{
			NIGHT = 1440 - start;
		}

		if(end > start){

			if(end>= 0 && end < 480){
				NIGHT -= 600 - end;
				DAY -= 600;
				EVEN -= 240;
			}else if(end >= 480 && end < 1080){
				DAY -= 1080 - end;
				EVEN -= 240;
				NIGHT -= 120;
			}else if(end >= 1080 && end < 1320){
				EVEN -= 1320 - end;
				NIGHT -= 120;
			}else{
				NIGHT -= 1440 - end;
			}

		}else{

			if(end >= 0 && end < 480){
				NIGHT += end;
			}else if(end >= 480 && end < 1080){
				NIGHT += 480;
				DAY += end - 480;
			}else if(end >= 1080 && end < 1320){
				NIGHT += 480;
				DAY += 600;
				EVEN += end - 1080;
			}else{
				NIGHT += 480;
				DAY += 600;
				EVEN += 240;
				NIGHT += end - 1320;
			}

		}

		c = plan[0] - 'A';
		FEE = DAY * hash[c][0] + EVEN * hash[c][1] + NIGHT * hash[c][2];
		printf("%10s%6d%6d%6d  %c%8.2f\n", bill, DAY, EVEN, NIGHT, plan[0], FEE);
	}
	return 0;
}
