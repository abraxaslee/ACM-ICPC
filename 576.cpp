//2012/01/20
//576.cpp
//Run time: 0.004

#include <stdio.h>

char buff[205];
int check[3] = { 5, 7, 5 };

int i, z, vows, now, wrong;

int isVowels(int c){
	if( c == 'a' | c == 'e' | c == 'i' | c == 'o' | c == 'u' | c == 'y')
		if(!now)
			return now = 1;
		else
			return 0;
	return now = 0;
}

void solve(){

	if(buff[5] == '\0')
		if(buff[0] == 'e' & buff[2] == 'o' & buff[4] == 'i')
			return;

	for(i = wrong = z = 0; i < 3 & !wrong; ++i){
		for(vows = now = 0; buff[z] != '/' & buff[z] != '\0' ; ++z)
			if(isVowels(buff[z]))
				++vows;

		if(vows != check[i])
			wrong = i+1;
		++z;
	}

	if(!wrong)
		putchar('Y');
	else
		putchar(wrong+48);

	putchar(10);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("576.in", "r", stdin);
	freopen("576.out", "w", stdout);
	#endif

	while(gets(buff) != NULL)
		solve();

	return 0;
}
