//2012/02/18
//11069.cpp
//Run time: 0.004

#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11069.in", "r", stdin);
	freopen("11069.out", "w", stdout);
	#endif

	int dp[77], input;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 4;
	dp[6] = 5;
	dp[7] = 7;
	dp[8] = 9;
	dp[9] = 12;
	dp[10] = 16;
	dp[11] = 21;
	dp[12] = 28;
	dp[13] = 37;
	dp[14] = 49;
	dp[15] = 65;
	dp[16] = 86;
	dp[17] = 114;
	dp[18] = 151;
	dp[19] = 200;
	dp[20] = 265;
	dp[21] = 351;
	dp[22] = 465;
	dp[23] = 616;
	dp[24] = 816;
	dp[25] = 1081;
	dp[26] = 1432;
	dp[27] = 1897;
	dp[28] = 2513;
	dp[29] = 3329;
	dp[30] = 4410;
	dp[31] = 5842;
	dp[32] = 7739;
	dp[33] = 10252;
	dp[34] = 13581;
	dp[35] = 17991;
	dp[36] = 23833;
	dp[37] = 31572;
	dp[38] = 41824;
	dp[39] = 55405;
	dp[40] = 73396;
	dp[41] = 97229;
	dp[42] = 128801;
	dp[43] = 170625;
	dp[44] = 226030;
	dp[45] = 299426;
	dp[46] = 396655;
	dp[47] = 525456;
	dp[48] = 696081;
	dp[49] = 922111;
	dp[50] = 1221537;
	dp[51] = 1618192;
	dp[52] = 2143648;
	dp[53] = 2839729;
	dp[54] = 3761840;
	dp[55] = 4983377;
	dp[56] = 6601569;
	dp[57] = 8745217;
	dp[58] = 11584946;
	dp[59] = 15346786;
	dp[60] = 20330163;
	dp[61] = 26931732;
	dp[62] = 35676949;
	dp[63] = 47261895;
	dp[64] = 62608681;
	dp[65] = 82938844;
	dp[66] = 109870576;
	dp[67] = 145547525;
	dp[68] = 192809420;
	dp[69] = 255418101;
	dp[70] = 338356945;
	dp[71] = 448227521;
	dp[72] = 593775046;
	dp[73] = 786584466;
	dp[74] = 1042002567;
	dp[75] = 1380359512;
	dp[76] = 1828587033;
	while(scanf("%d", &input) == 1)
		printf("%d\n", dp[atoi(buff)]);
	return 0;
}
