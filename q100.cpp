//Q100: The 3n + 1 problem
//accepted at 2011-08-28 09:03:29
//run time = 0.652

#include <stdio.h>
#include <algorithm>
using namespace std;


inline int runcyc(int i, int j); //run the cyc
int cyctest(int num); //return the length of a certain int

int main(void){
	int i,j ;
	while (scanf("%d %d", &i, &j)!= EOF){
	printf("%d %d %d\n", i, j, runcyc(i,j));
	}
	return 0;
}

inline int cyctest(int num){
	int nCon = 1;
	do{
		if (num == 1){
		return nCon;
		}

		if ((num%2)){
			num = 3 * num++;
		}else{
			num /= 2;
		}
		nCon++;
	}while(num >1);
	return nCon;
}

int runcyc(int i, int j){
	int maxleng = 1;
	if(i>j){
		swap(i,j);
	}
	while(i <= j){
		maxleng = max(maxleng,cyctest(i));
		i++;
	}
	return maxleng;
}

