//q501.cpp - 2011/12/31
//accepted at 
//run time = 
#include <stdio.h>

int buff[30005];
int btop;

int max[30005];
int xtop;

int min[30005];
int ntop;
void minpush(int x){
	int i = ntop++;
	while( i > 0){
		int p = (i - 1)/2;
		if( min[p] <= x )	break;
		min[i] = min[p];
		i = p;
	}
	min[i] = x;
	return;
}
int minpop(){
	int out = min[0];
	int x = min[--ntop];
	int i = 0;
	while( i *2 + 1 < ntop){
		int a = i * 2 + 1, b = i * 2 + 2;
		if( b < ntop && min[b] < min[a])	a = b;
		if(min[a] >= x)		break;
		min[i] = min[a];
		i = a;
	}
	min[i] = x;
	return out;
}
void maxpush(int x){
	int i = xtop++;
	while( i > 0){
		int p = (i - 1)/2;
		if( max[p] >= x )	break;
		max[i] = max[p];
		i = p;
	}
	max[i] = x;
	return;
}
int maxpop(){
	int out = max[0];
	int x = max[--xtop];
	int i = 0;
	while( i *2 + 1 < xtop){
		int a = i * 2 + 1, b = i * 2 + 2;
		if( b < xtop && max[b] > max[a])	a = b;
		if(max[a] <= x)		break;
		max[i] = max[a];
		i = a;
	}
	max[i] = x;
	return out;
}

void showmax(){
	int i;
	printf("max %d :\n", xtop);
	for(i=0;i<xtop; ++i)
		printf("%d ", max[i]);
	putchar(10);
}

void showmin(){
	int i;
	printf("min %d :\n", ntop);
	for(i=0;i<ntop; ++i)
		printf("%d ", min[i]);
	putchar(10);
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q501.in", "r", stdin);
	freopen("q501.out", "w", stdout);
	#endif

	int caseNum, i, cmd, tmp, cnt, once = 0;
	scanf("%d", &caseNum);

	while(caseNum--){

		if(once)
			putchar(10);

		scanf("%d%d", &btop, &cmd);
		for(i=0; i<btop; ++i)
			scanf("%d", &buff[i]);

		cnt = ntop = xtop = i = 0;
		while(cmd--){
			scanf("%d", &tmp);

			while(i<tmp){
				if(ntop > 0 && buff[i] <= min[0])
					maxpush(buff[i++]);
				else
					minpush(buff[i++]);
			}

			while(xtop > cnt)
				minpush(maxpop());

			while(xtop < cnt)
				maxpush(minpop());

			printf("%d\n", min[0]);
			cnt++;
		}
		once = 1;

	}
	return 0;
}
