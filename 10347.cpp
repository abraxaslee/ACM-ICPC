//2012/03/25
//10347.cpp
//Run time: 0.008

#include <stdio.h>
#include <math.h>
int main(){

	#ifndef ONLINE_JUDGE
	freopen("10347.in", "r", stdin);
	freopen("10347.out", "w", stdout);
	#endif

	double ma, mb, mc, sm, Area;
	while(scanf("%lf%lf%lf", &ma, &mb, &mc) == 3){
		if(ma <= 0 || mb <= 0 || mc <=0 )	{puts("-1.000"); continue;}
		sm = 0.5 * (ma + mb + mc);
		Area = sm * (sm - ma) * (sm - mb) * (sm - mc);
		if(Area <= 0)	{puts("-1.000"); continue;}
		Area = sqrt(Area) * 4 / 3;
		printf("%.3f\n", Area);
	}

	return 0;
}
