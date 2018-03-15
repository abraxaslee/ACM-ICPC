//0.004

#include <stdio.h>

int keyboard[128] = {};

int main(){
	
	keyboard[49] = 96;
	keyboard[50] = 49;
	keyboard[51] = 50;
	keyboard[52] = 51;
	keyboard[53] = 52;
	keyboard[54] = 53;
	keyboard[55] = 54;
	keyboard[56] = 55;
	keyboard[57] = 56;
	keyboard[48] = 57;
	keyboard[45] = 48;
	keyboard[61] = 45;

	keyboard[87] = 81;
	keyboard[69] = 87;
	keyboard[82] = 69;
	keyboard[84] = 82;
	keyboard[89] = 84;
	keyboard[85] = 89;
	keyboard[73] = 85;
	keyboard[79] = 73;
	keyboard[80] = 79;
	keyboard[91] = 80;
	keyboard[93] = 91;
	keyboard[92] = 93;

	keyboard[83] = 65;
	keyboard[68] = 83;
	keyboard[70] = 68;
	keyboard[71] = 70;
	keyboard[72] = 71;
	keyboard[74] = 72;
	keyboard[75] = 74;
	keyboard[76] = 75;
	keyboard[59] = 76;
	keyboard[39] = 59;

	keyboard[88] = 90;
	keyboard[67] = 88;
	keyboard[86] = 67;
	keyboard[66] = 86;
	keyboard[78] = 66;
	keyboard[77] = 78;
	keyboard[44] = 77;
	keyboard[46] = 44;
	keyboard[47] = 46;

	keyboard[32] = 32;
	keyboard[10] = 10;
	int c;
	while((c=getchar())!=EOF){
		putchar(keyboard[c]);
	}
	return 0;
}
