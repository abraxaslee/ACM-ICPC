// 0.008
#include <stdio.h>
using namespace std;

int main(){
	char ctop[110] = {}, cmid[110] = {}, cbot[110] = {};
	char ctextUp[110] = {}, ctextDown[110] = {};
	int size = 0;
	char c;

	while(scanf("%d", &size)!=EOF){
		getchar();
		int last = 0;
		for(int i=0; i<110 ;i++){
			ctop[i] = 32;
			cmid[i] = 32;
			cbot[i] = 32;
			ctextUp[i] = 32;
			ctextDown[i] = 32;
		}
			while( (c=getchar())!='\n'){
				if(c==48&&size==0){
					return 0;
				}
				switch(c-48){
					case 1:
						ctextUp[last+size+1] = '|';
						ctextDown[last+size+1] = '|';
						break;

					case 2:
						ctextUp[last+size+1] = '|';
						ctextDown[last] = '|';
						for(int i=0;i<size;i++){
							ctop[last+i+1] = '-';
							cmid[last+i+1] = '-';
							cbot[last+i+1] = '-';
						}
						break;
					case 3:
						ctextUp[last+size+1] = '|';
						ctextDown[last+size+1] = '|';
						for(int i=0;i<size;i++){
							ctop[last+i+1] = '-';
							cmid[last+i+1] = '-';
							cbot[last+i+1] = '-';
						}
						break;
					case 4:
						ctextUp[last] = '|';
						ctextUp[last+size+1] = '|';
						ctextDown[last+size+1] = '|';
						for(int i=0;i<size;i++){
							cmid[last+i+1] = '-';
						}
						break;
					case 5:
						ctextUp[last] = '|';
						ctextDown[last+size+1] = '|';
						for(int i=0;i<size;i++){
							ctop[last+i+1] = '-';
							cmid[last+i+1] = '-';
							cbot[last+i+1] = '-';
						}
						break;
					case 6:
						ctextUp[last] = '|';
						ctextDown[last] = '|';
						ctextDown[last+size+1] = '|';
						for(int i=0;i<size;i++){
							ctop[last+i+1] = '-';
							cmid[last+i+1] = '-';
							cbot[last+i+1] = '-';
						}
						break;
					case 7:
						ctextUp[last+size+1] = '|';
						ctextDown[last+size+1] = '|';
						for(int i=0;i<size;i++){
							ctop[last+i+1] = '-';
						}
						break;
					case 8:
						ctextUp[last] = '|';
						ctextUp[last+size+1] = '|';
						ctextDown[last] = '|';
						ctextDown[last+size+1] = '|';
						for(int i=0;i<size;i++){
							ctop[last+i+1] = '-';
							cmid[last+i+1] = '-';
							cbot[last+i+1] = '-';
						}
						break;
					case 9:
						ctextUp[last] = '|';
						ctextUp[last+size+1] = '|';
						ctextDown[last+size+1] = '|';
						for(int i=0;i<size;i++){
							ctop[last+i+1] = '-';
							cmid[last+i+1] = '-';
							cbot[last+i+1] = '-';
						}
						break;
					case 0:
						ctextUp[last] = '|';
						ctextUp[last+size+1] = '|';
						ctextDown[last] = '|';
						ctextDown[last+size+1] = '|';
						for(int i=0;i<size;i++){
							ctop[last+i+1] = '-';
							cbot[last+i+1] = '-';
						}
						break;
					default:
						continue;
				}
				last = last + size + 3;
			}
			last -= 1;
			ctop[last] = '\0';
			cmid[last] = '\0';
			cbot[last] = '\0';
			ctextUp[last] = '\0';
			ctextDown[last] = '\0';
		puts(ctop);
		for(int i=0;i<size;i++){
			puts(ctextUp);
		}
		puts(cmid);
		for(int i=0;i<size;i++){
			puts(ctextDown);
		}
		puts(cbot);
		putchar(10);
	}

	return 0;
}
