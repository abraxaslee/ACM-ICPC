//q443.cpp - 2011/11/27
//accepted at 
//run time = 0.012
#include <stdio.h>

int humble[5843];
int top;

int min(int A, int B){
	return A < B ? A : B;
}

void build_humble(){
	int p2, p3, p5, p7, m2, m3, m5, m7;
	humble[1] = p2 = p3 = p5 = p7 = top = 1;

	m2 = 2*humble[p2], m3 = 3*humble[p3], m5 = 5*humble[p5], m7 = 7*humble[p7];
	while( top < 5842 ){
		humble[++top] = min( m2, min( m3, min( m5, m7) ) );
		//printf("DEBUG : humble[%d] = %d.\n", top, humble[top]);
		if(humble[top] == m2)	m2 = 2*humble[++p2];
		if(humble[top] == m3)	m3 = 3*humble[++p3];
		if(humble[top] == m5)	m5 = 5*humble[++p5];
		if(humble[top] == m7)	m7 = 7*humble[++p7];
	}
	return;
}

void printNumber(int n){
	int last = n %10;
	int ten = n % 100;
	printf("The %d", n);
	if(ten == 11 || ten == 12 || ten == 13)	printf("th");
	else if(last == 1)	printf("st");
	else if(last == 2)	printf("nd");
	else if(last == 3)	printf("rd");
	else	printf("th");

	printf(" humble number is %d.\n", humble[n]);
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q443.in", "r", stdin);
	freopen("q443.out", "w", stdout);
	#endif

	build_humble();
	int input;
	while(scanf("%d", &input)!=EOF){
		if(input == 0)	break;
		printNumber(input);
	}
	return 0;
}
