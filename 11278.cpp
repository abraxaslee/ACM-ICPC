//2012/03/08
//11278.cpp
//Run time: 0.004

#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11278.in", "r", stdin);
	freopen("11278.out", "w", stdout);
	#endif

	register int k[300];

	k[10] = 10; k[' '] = ' ';
	k['`'] = '`';
	k['1'] = '1';
	k['2'] = '2';
	k['3'] = '3';
	k['4'] = 'q';
	k['5'] = 'j';
	k['6'] = 'l';
	k['7'] = 'm';
	k['8'] = 'f';
	k['9'] = 'p';
	k['0'] = '/';
	k['-'] = '[';
	k['='] = ']';

	k['q'] = '4';
	k['w'] = '5';
	k['e'] = '6';
	k['r'] = '.';
	k['t'] = 'o';
	k['y'] = 'r';
	k['u'] = 's';
	k['i'] = 'u';
	k['o'] = 'y';
	k['p'] = 'b';
	k['['] = ';';
	k[']'] = '=';
	k['\\'] = '\\';

	k['a'] = '7';
	k['s'] = '8';
	k['d'] = '9';
	k['f'] = 'a';
	k['g'] = 'e';
	k['h'] = 'h';
	k['j'] = 't';
	k['k'] = 'd';
	k['l'] = 'c';
	k[';'] = 'k';
	k['\''] = '-';

	k['z'] = '0';
	k['x'] = 'z';
	k['c'] = 'x';
	k['v'] = ',';
	k['b'] = 'i';
	k['n'] = 'n';
	k['m'] = 'w';
	k[','] = 'v';
	k['.'] = 'g';
	k['/'] = '\'';

	k['~'] = '~';
	k['!'] = '!';
	k['@'] = '@';
	k['#'] = '#';
	k['$'] = 'Q';
	k['%'] = 'J';
	k['^'] = 'L';
	k['&'] = 'M';
	k['*'] = 'F';
	k['('] = 'P';
	k[')'] = '?';
	k['_'] = '{';
	k['+'] = '}';

	k['Q'] = '$';
	k['W'] = '%';
	k['E'] = '^';
	k['R'] = '>';
	k['T'] = 'O';
	k['Y'] = 'R';
	k['U'] = 'S';
	k['I'] = 'U';
	k['O'] = 'Y';
	k['P'] = 'B';
	k['{'] = ':';
	k['}'] = '+';
	k['|'] = '|';

	k['A'] = '&';
	k['S'] = '*';
	k['D'] = '(';
	k['F'] = 'A';
	k['G'] = 'E';
	k['H'] = 'H';
	k['J'] = 'T';
	k['K'] = 'D';
	k['L'] = 'C';
	k[':'] = 'K';
	k['"'] = '_';

	k['Z'] = ')';
	k['X'] = 'Z';
	k['C'] = 'X';
	k['V'] = '<';
	k['B'] = 'I';
	k['N'] = 'N';
	k['M'] = 'W';
	k['<'] = 'V';
	k['>'] = 'G';
	k['?'] = '"';

	int c;
	while( (c = getchar()) != EOF){
		putchar(k[c]);
	}
	return 0;
}
