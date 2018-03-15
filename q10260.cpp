//q10260.cpp - 2011/10/20
//accepted at 
//run time = 0.004 (c)
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10260.in", "r", stdin);
	freopen("q10260.out", "w", stdout);
	#endif

	int c, past;
	while( (c=getchar()) != EOF){

		switch(c){

			case 10:
				past = 0;
				putchar(10);
				break;

			case 66:
			case 70:
			case 80:
			case 86:
				if(past==49){break;}
				putchar(49);
				past = 49;
				break;

			case 67:
			case 71:
			case 74:
			case 75:
			case 81:
			case 83:
			case 88:
			case 90:
				if(past==50){break;}
				putchar(50);
				past = 50;
				break;

			case 68:
			case 84:
				if(past==51){break;}
				putchar(51);
				past = 51;
				break;

			case 76:
				if(past==52){break;}
				putchar(52);
				past = 52;
				break;

			case 77:
			case 78:
				if(past==53){break;}
				putchar(53);
				past = 53;
				break;

			case 82:
				if(past==54){break;}
				putchar(54);
				past = 54;
				break;

			default:
				past = 0;
				break;
		}

	}
	return 0;
}
