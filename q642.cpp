//q642.cpp - 2011/12/26
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <string.h>
char dictionary[100][10];
int word[100][26];
int length[100];
int top;

char buff[10];
int output[100];
void quicksort( int start, int end, int array[])
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ )
            if( strcmp(dictionary[array[i]], dictionary[array[start]]) < 0 )
            {
                piv++;

                temp = array[i];
                array[i] = array[piv];
                array[piv] = temp;
            }

        temp = array[start];
        array[start] = array[piv];
        array[piv] = temp;

        quicksort( start, piv, array );
        quicksort( piv+1, end, array );
    }
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q642.in", "r", stdin);
	freopen("q642.out", "w", stdout);
	#endif

	int i, z;
	while(gets(dictionary[top]) != NULL){
		if(dictionary[top][0] == 'X')	break;
		for(i=0; dictionary[top][i] != '\0'; ++i)
			word[top][dictionary[top][i]-'a']++;
		length[top++] = i;
	}

	int bLength, outTop;
	while(gets(buff) != NULL){
		int bWord[26] = {};
		outTop = 0;
		if(buff[0] == 'X')	break;
		for(i=0; buff[i] != '\0'; ++i)
			bWord[buff[i]-'a']++;
		bLength = i;
		for(i=0; i<top; ++i){
			if(bLength == length[i]){
				for(z=0; z<26; ++z)
					if(word[i][z] != bWord[z])
						break;
				if(z==26){
					output[outTop++] = i;
				}
			}
		}
		if(outTop == 0)
			puts("NOT A VALID WORD");
		else{
			quicksort(0, outTop, output);
			for(i=0; i<outTop; ++i)
				puts(dictionary[output[i]]);
		}

		puts("******");
	}
	return 0;
}
