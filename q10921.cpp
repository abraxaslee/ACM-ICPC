//q10921.cpp - 2011/11/15
//accepted at 
//run time = 0.004
#include <stdio.h>

char keypad[128];

void build_keypad(){
	keypad[10] = 10;
	keypad[32] = 32; keypad[45] = 45;
	keypad[48] = 48;
	keypad[49] = 49;
	keypad[50] = 50;
	keypad[51] = 51;
	keypad[52] = 52;
	keypad[53] = 53;
	keypad[54] = 54;
	keypad[55] = 55;
	keypad[56] = 56;
	keypad[57] = 57;

	keypad[65] = 50; keypad[66] = 50; keypad[67] = 50;
	keypad[68] = 51; keypad[69] = 51; keypad[70] = 51;
	keypad[71] = 52; keypad[72] = 52; keypad[73] = 52;
	keypad[74] = 53; keypad[75] = 53; keypad[76] = 53;
	keypad[77] = 54; keypad[78] = 54; keypad[79] = 54;
	keypad[80] = 55; keypad[81] = 55; keypad[82] = 55; keypad[83] = 55;
	keypad[84] = 56; keypad[85] = 56; keypad[86] = 56;
	keypad[87] = 57; keypad[88] = 57; keypad[89] = 57; keypad[90] = 57;
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10921.in", "r", stdin);
	freopen("q10921.out", "w", stdout);
	#endif

	build_keypad();

	int c;
	while((c = getchar())!=EOF){
		putchar(keypad[c]);
	}
	return 0;
}
