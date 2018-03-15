//2012/02/26
//11239.cpp
//Run time: 0.016

#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

char projects[100][1000];
int score[100];
int output[100];
char buff[1000];

int top;

void quicksort( int start, int end )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ )
            if( score[output[i]] > score[output[start]] || (score[output[i]] == score[output[start]] && strcmp(projects[output[i]], projects[output[start]]) < 0))
            {
                piv++;

                temp = output[i];
                output[i] = output[piv];
                output[piv] = temp;
            }


        temp = output[start];
        output[start] = output[piv];
        output[piv] = temp;

        quicksort( start, piv );
        quicksort( piv+1, end );
    }
}

bool notLower(char x){
	return !(x > 96 && x < 123);
}

void solve(){
	map<string, int> student;
	top = -1;

	while(buff[0] != '1'){
		if( notLower(buff[0]) ){
			++top;
			score[top] = 0;
			output[top] = top;
			strcpy(projects[top], buff);
		}else{
			if( student.find(buff) == student.end() ){
				student.insert( pair<string, int>(buff, top) );
				++score[top];
			}else if(student[buff] >= 0 && student[buff] != top){
					--score[student[buff]];
					student[buff] = -1;
			}
		}
		if(gets(buff) == NULL)	break;
	}
	++top;
	quicksort(0, top);
	for(int i = 0; i < top; ++i)
		printf("%s %d\n", projects[output[i]], score[output[i]]);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11239.in", "r", stdin);
	freopen("11239.out", "w", stdout);
	#endif

	while(gets(buff) != NULL){
		if(buff[0] == '0')	break;
		solve();
	}
	return 0;
}
