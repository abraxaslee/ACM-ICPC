//2012/02/19
//10033.cpp
//Run time: 0.004

#include <stdio.h>
#include <stdlib.h>
#define REG_MAX 1000

int once;
int main(){

	#ifndef ONLINE_JUDGE
	freopen("10033.in", "r", stdin);
	freopen("10033.out", "w", stdout);
	#endif

	int testCase;
	scanf("%d", &testCase);
	getchar();	getchar();
	int mpos, pos, notHalt, cmd, rd, rs, ans;
	char buff[10];
	while(testCase--){

		int reg[10] = {};
		int mem[1000] = {};

		mpos = 0;

		while(gets(buff) != NULL & buff[0] != '\0')
			mem[mpos++] = atoi(buff);

		notHalt = 1;
		ans = pos = 0;

		while(notHalt){

			cmd = mem[pos]/100;
			rd = (mem[pos]%100)/10;
			rs = mem[pos]%10;

			++pos, ++ans;

			switch(cmd){
				case 1:
					notHalt = 0;
					break;

				case 2:
					reg[rd] = rs;
					break;

				case 3:
					reg[rd] += rs;
					if(reg[rd] >= REG_MAX)
						reg[rd] %= REG_MAX;
					break;

				case 4:
					reg[rd] *= rs;
					if(reg[rd] >= REG_MAX)
						reg[rd] %= REG_MAX;
					break;

				case 5:
					reg[rd] = reg[rs];
					break;

				case 6:
					reg[rd] += reg[rs];
					if(reg[rd] >= REG_MAX)
						reg[rd] %= REG_MAX;
					break;

				case 7:
					reg[rd] *= reg[rs];
					if(reg[rd] >= REG_MAX)
						reg[rd] %= REG_MAX;
					break;

				case 8:
					reg[rd] = mem[reg[rs]];
					break;

				case 9:
					mem[reg[rs]] = reg[rd];
					break;

				case 0:
					if(reg[rs] != 0) pos = reg[rd];
					break;
			}
		}
		if(once)  putchar(10);
		printf("%d\n", ans);
		once = 1;
	}
	return 0;
}
