//q386.cpp - 2011/11/01
//accepted at 
//run time = 0.664
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q386.in", "r", stdin);
	freopen("q386.out", "w", stdout);
	#endif

	int tmp[4] = {};
	for(int a=6;a<=200;++a){
		bool bam[200] = {};
		tmp[0] = a*a*a;
		tmp[1] = 0; tmp[2] = 0; tmp[3] = 0;
		for(int b=2;tmp[1]<=tmp[0];++b){
			tmp[1] = b*b*b; tmp[2] = 0; tmp[3] = 0;
			for(int c=2;tmp[2]<=tmp[0];++c){
				tmp[2] = tmp[1] + c*c*c;
				tmp[3] = 0;
				for(int d=2;tmp[3]<=tmp[0];++d){
					tmp[3] = tmp[2] + d*d*d;
					if(tmp[3] == tmp[0] && ( !bam[b] || !bam[c] || !bam[d] )){
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
						bam[b] = true; bam[c] = true; bam[d] = true;
					}
				}
			}
		}
	}
	return 0;
}
