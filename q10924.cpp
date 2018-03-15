//q10924.cpp - 2011/11/11
//accepted at 
//run time = 0.008 / 0.004c
#include <stdio.h>

bool prime[1050] = {};
char buff[25];

void prime_table(){
	prime[1] = true;
	prime[2] = true;
	prime[3] = true;
	prime[5] = true;
	prime[7] = true;
	prime[11] = true;
	prime[13] = true;
	prime[17] = true;
	prime[19] = true;
	prime[23] = true;
	prime[29] = true;
	prime[31] = true;
	prime[37] = true;
	prime[41] = true;
	prime[43] = true;
	prime[47] = true;
	prime[53] = true;
	prime[59] = true;
	prime[61] = true;
	prime[67] = true;
	prime[71] = true;
	prime[73] = true;
	prime[79] = true;
	prime[83] = true;
	prime[89] = true;
	prime[97] = true;
	prime[101] = true;
	prime[103] = true;
	prime[107] = true;
	prime[109] = true;
	prime[113] = true;
	prime[127] = true;
	prime[131] = true;
	prime[137] = true;
	prime[139] = true;
	prime[149] = true;
	prime[151] = true;
	prime[157] = true;
	prime[163] = true;
	prime[167] = true;
	prime[173] = true;
	prime[179] = true;
	prime[181] = true;
	prime[191] = true;
	prime[193] = true;
	prime[197] = true;
	prime[199] = true;
	prime[211] = true;
	prime[223] = true;
	prime[227] = true;
	prime[229] = true;
	prime[233] = true;
	prime[239] = true;
	prime[241] = true;
	prime[251] = true;
	prime[257] = true;
	prime[263] = true;
	prime[269] = true;
	prime[271] = true;
	prime[277] = true;
	prime[281] = true;
	prime[283] = true;
	prime[293] = true;
	prime[307] = true;
	prime[311] = true;
	prime[313] = true;
	prime[317] = true;
	prime[331] = true;
	prime[337] = true;
	prime[347] = true;
	prime[349] = true;
	prime[353] = true;
	prime[359] = true;
	prime[367] = true;
	prime[373] = true;
	prime[379] = true;
	prime[383] = true;
	prime[389] = true;
	prime[397] = true;
	prime[401] = true;
	prime[409] = true;
	prime[419] = true;
	prime[421] = true;
	prime[431] = true;
	prime[433] = true;
	prime[439] = true;
	prime[443] = true;
	prime[449] = true;
	prime[457] = true;
	prime[461] = true;
	prime[463] = true;
	prime[467] = true;
	prime[479] = true;
	prime[487] = true;
	prime[491] = true;
	prime[499] = true;
	prime[503] = true;
	prime[509] = true;
	prime[521] = true;
	prime[523] = true;
	prime[541] = true;
	prime[547] = true;
	prime[557] = true;
	prime[563] = true;
	prime[569] = true;
	prime[571] = true;
	prime[577] = true;
	prime[587] = true;
	prime[593] = true;
	prime[599] = true;
	prime[601] = true;
	prime[607] = true;
	prime[613] = true;
	prime[617] = true;
	prime[619] = true;
	prime[631] = true;
	prime[641] = true;
	prime[643] = true;
	prime[647] = true;
	prime[653] = true;
	prime[659] = true;
	prime[661] = true;
	prime[673] = true;
	prime[677] = true;
	prime[683] = true;
	prime[691] = true;
	prime[701] = true;
	prime[709] = true;
	prime[719] = true;
	prime[727] = true;
	prime[733] = true;
	prime[739] = true;
	prime[743] = true;
	prime[751] = true;
	prime[757] = true;
	prime[761] = true;
	prime[769] = true;
	prime[773] = true;
	prime[787] = true;
	prime[797] = true;
	prime[809] = true;
	prime[811] = true;
	prime[821] = true;
	prime[823] = true;
	prime[827] = true;
	prime[829] = true;
	prime[839] = true;
	prime[853] = true;
	prime[857] = true;
	prime[859] = true;
	prime[863] = true;
	prime[877] = true;
	prime[881] = true;
	prime[883] = true;
	prime[887] = true;
	prime[907] = true;
	prime[911] = true;
	prime[919] = true;
	prime[929] = true;
	prime[937] = true;
	prime[941] = true;
	prime[947] = true;
	prime[953] = true;
	prime[967] = true;
	prime[971] = true;
	prime[977] = true;
	prime[983] = true;
	prime[991] = true;
	prime[997] = true;
	prime[1009] = true;
	prime[1013] = true;
	prime[1019] = true;
	prime[1021] = true;
	prime[1031] = true;
	prime[1033] = true;
	prime[1039] = true;
}

inline int solve(){
	int i, result = 0;
	for(i=0;buff[i]!='\0';++i){
		if(buff[i]>=97){
			result += buff[i] - 96;
		}else{
			result += buff[i] - 38;
		}
	}
	return result;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10924.in", "r", stdin);
	freopen("q10924.out", "w", stdout);
	#endif

	prime_table();
	while(gets(buff)!=NULL){
		if(prime[solve()] == true){
			puts("It is a prime word.");
		}else{
			puts("It is not a prime word.");
		}
	}
	return 0;
}
