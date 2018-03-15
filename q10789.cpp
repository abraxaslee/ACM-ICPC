//q10789.cpp - 2011/11/21
//accepted at 
//run time = 0.020
#include <stdio.h>
int prime[303];

int binarySearch(int search, int data[]){
	int low = 0, high = 302, mid;

	while(low <= high){

		mid = (low + high)/2;

		if(data[mid] == search)
			return mid;
		else if(search > data[mid])
			low = mid + 1;
		else if(data[mid] > search)
			high = mid - 1;

	}

	return -1;
}

void build_prime(){
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime[4] = 11;
	prime[5] = 13;
	prime[6] = 17;
	prime[7] = 19;
	prime[8] = 23;
	prime[9] = 29;
	prime[10] = 31;
	prime[11] = 37;
	prime[12] = 41;
	prime[13] = 43;
	prime[14] = 47;
	prime[15] = 53;
	prime[16] = 59;
	prime[17] = 61;
	prime[18] = 67;
	prime[19] = 71;
	prime[20] = 73;
	prime[21] = 79;
	prime[22] = 83;
	prime[23] = 89;
	prime[24] = 97;
	prime[25] = 101;
	prime[26] = 103;
	prime[27] = 107;
	prime[28] = 109;
	prime[29] = 113;
	prime[30] = 127;
	prime[31] = 131;
	prime[32] = 137;
	prime[33] = 139;
	prime[34] = 149;
	prime[35] = 151;
	prime[36] = 157;
	prime[37] = 163;
	prime[38] = 167;
	prime[39] = 173;
	prime[40] = 179;
	prime[41] = 181;
	prime[42] = 191;
	prime[43] = 193;
	prime[44] = 197;
	prime[45] = 199;
	prime[46] = 211;
	prime[47] = 223;
	prime[48] = 227;
	prime[49] = 229;
	prime[50] = 233;
	prime[51] = 239;
	prime[52] = 241;
	prime[53] = 251;
	prime[54] = 257;
	prime[55] = 263;
	prime[56] = 269;
	prime[57] = 271;
	prime[58] = 277;
	prime[59] = 281;
	prime[60] = 283;
	prime[61] = 293;
	prime[62] = 307;
	prime[63] = 311;
	prime[64] = 313;
	prime[65] = 317;
	prime[66] = 331;
	prime[67] = 337;
	prime[68] = 347;
	prime[69] = 349;
	prime[70] = 353;
	prime[71] = 359;
	prime[72] = 367;
	prime[73] = 373;
	prime[74] = 379;
	prime[75] = 383;
	prime[76] = 389;
	prime[77] = 397;
	prime[78] = 401;
	prime[79] = 409;
	prime[80] = 419;
	prime[81] = 421;
	prime[82] = 431;
	prime[83] = 433;
	prime[84] = 439;
	prime[85] = 443;
	prime[86] = 449;
	prime[87] = 457;
	prime[88] = 461;
	prime[89] = 463;
	prime[90] = 467;
	prime[91] = 479;
	prime[92] = 487;
	prime[93] = 491;
	prime[94] = 499;
	prime[95] = 503;
	prime[96] = 509;
	prime[97] = 521;
	prime[98] = 523;
	prime[99] = 541;
	prime[100] = 547;
	prime[101] = 557;
	prime[102] = 563;
	prime[103] = 569;
	prime[104] = 571;
	prime[105] = 577;
	prime[106] = 587;
	prime[107] = 593;
	prime[108] = 599;
	prime[109] = 601;
	prime[110] = 607;
	prime[111] = 613;
	prime[112] = 617;
	prime[113] = 619;
	prime[114] = 631;
	prime[115] = 641;
	prime[116] = 643;
	prime[117] = 647;
	prime[118] = 653;
	prime[119] = 659;
	prime[120] = 661;
	prime[121] = 673;
	prime[122] = 677;
	prime[123] = 683;
	prime[124] = 691;
	prime[125] = 701;
	prime[126] = 709;
	prime[127] = 719;
	prime[128] = 727;
	prime[129] = 733;
	prime[130] = 739;
	prime[131] = 743;
	prime[132] = 751;
	prime[133] = 757;
	prime[134] = 761;
	prime[135] = 769;
	prime[136] = 773;
	prime[137] = 787;
	prime[138] = 797;
	prime[139] = 809;
	prime[140] = 811;
	prime[141] = 821;
	prime[142] = 823;
	prime[143] = 827;
	prime[144] = 829;
	prime[145] = 839;
	prime[146] = 853;
	prime[147] = 857;
	prime[148] = 859;
	prime[149] = 863;
	prime[150] = 877;
	prime[151] = 881;
	prime[152] = 883;
	prime[153] = 887;
	prime[154] = 907;
	prime[155] = 911;
	prime[156] = 919;
	prime[157] = 929;
	prime[158] = 937;
	prime[159] = 941;
	prime[160] = 947;
	prime[161] = 953;
	prime[162] = 967;
	prime[163] = 971;
	prime[164] = 977;
	prime[165] = 983;
	prime[166] = 991;
	prime[167] = 997;
	prime[168] = 1009;
	prime[169] = 1013;
	prime[170] = 1019;
	prime[171] = 1021;
	prime[172] = 1031;
	prime[173] = 1033;
	prime[174] = 1039;
	prime[175] = 1049;
	prime[176] = 1051;
	prime[177] = 1061;
	prime[178] = 1063;
	prime[179] = 1069;
	prime[180] = 1087;
	prime[181] = 1091;
	prime[182] = 1093;
	prime[183] = 1097;
	prime[184] = 1103;
	prime[185] = 1109;
	prime[186] = 1117;
	prime[187] = 1123;
	prime[188] = 1129;
	prime[189] = 1151;
	prime[190] = 1153;
	prime[191] = 1163;
	prime[192] = 1171;
	prime[193] = 1181;
	prime[194] = 1187;
	prime[195] = 1193;
	prime[196] = 1201;
	prime[197] = 1213;
	prime[198] = 1217;
	prime[199] = 1223;
	prime[200] = 1229;
	prime[201] = 1231;
	prime[202] = 1237;
	prime[203] = 1249;
	prime[204] = 1259;
	prime[205] = 1277;
	prime[206] = 1279;
	prime[207] = 1283;
	prime[208] = 1289;
	prime[209] = 1291;
	prime[210] = 1297;
	prime[211] = 1301;
	prime[212] = 1303;
	prime[213] = 1307;
	prime[214] = 1319;
	prime[215] = 1321;
	prime[216] = 1327;
	prime[217] = 1361;
	prime[218] = 1367;
	prime[219] = 1373;
	prime[220] = 1381;
	prime[221] = 1399;
	prime[222] = 1409;
	prime[223] = 1423;
	prime[224] = 1427;
	prime[225] = 1429;
	prime[226] = 1433;
	prime[227] = 1439;
	prime[228] = 1447;
	prime[229] = 1451;
	prime[230] = 1453;
	prime[231] = 1459;
	prime[232] = 1471;
	prime[233] = 1481;
	prime[234] = 1483;
	prime[235] = 1487;
	prime[236] = 1489;
	prime[237] = 1493;
	prime[238] = 1499;
	prime[239] = 1511;
	prime[240] = 1523;
	prime[241] = 1531;
	prime[242] = 1543;
	prime[243] = 1549;
	prime[244] = 1553;
	prime[245] = 1559;
	prime[246] = 1567;
	prime[247] = 1571;
	prime[248] = 1579;
	prime[249] = 1583;
	prime[250] = 1597;
	prime[251] = 1601;
	prime[252] = 1607;
	prime[253] = 1609;
	prime[254] = 1613;
	prime[255] = 1619;
	prime[256] = 1621;
	prime[257] = 1627;
	prime[258] = 1637;
	prime[259] = 1657;
	prime[260] = 1663;
	prime[261] = 1667;
	prime[262] = 1669;
	prime[263] = 1693;
	prime[264] = 1697;
	prime[265] = 1699;
	prime[266] = 1709;
	prime[267] = 1721;
	prime[268] = 1723;
	prime[269] = 1733;
	prime[270] = 1741;
	prime[271] = 1747;
	prime[272] = 1753;
	prime[273] = 1759;
	prime[274] = 1777;
	prime[275] = 1783;
	prime[276] = 1787;
	prime[277] = 1789;
	prime[278] = 1801;
	prime[279] = 1811;
	prime[280] = 1823;
	prime[281] = 1831;
	prime[282] = 1847;
	prime[283] = 1861;
	prime[284] = 1867;
	prime[285] = 1871;
	prime[286] = 1873;
	prime[287] = 1877;
	prime[288] = 1879;
	prime[289] = 1889;
	prime[290] = 1901;
	prime[291] = 1907;
	prime[292] = 1913;
	prime[293] = 1931;
	prime[294] = 1933;
	prime[295] = 1949;
	prime[296] = 1951;
	prime[297] = 1973;
	prime[298] = 1979;
	prime[299] = 1987;
	prime[300] = 1993;
	prime[301] = 1997;
	prime[302] = 1999;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10789.in", "r", stdin);
	freopen("q10789.out", "w", stdout);
	#endif

	build_prime();
	int caseNum, currentCase = 0, c, i, printed;
	scanf("%d", &caseNum);
	getchar();

	while(caseNum){
		int word[256] = {};
		printed = 0;
		while( (c = getchar()) && c != 10 ){
			word[c] += 1;
		}
		caseNum -= 1;
		printf("Case %d: ", ++currentCase);

		for(i=48;i<=57;++i)
			if(binarySearch(word[i],prime) >= 0){
				putchar(i);
				printed = 1;
			}

		for(i=65;i<=90;++i)
			if(binarySearch(word[i],prime) >= 0){
				putchar(i);
				printed = 1;
			}

		for(i=97;i<=122;++i)
			if(binarySearch(word[i],prime) >= 0){
				putchar(i);
				printed = 1;
			}

		if(printed == 0)
			puts("empty");
		else
			putchar(10);

	}
	return 0;
}
