//q755.cpp - 2011/10/21
//accepted at 
//run time = 0.412 (c)
#include <stdio.h>
#include <string.h>
const int pad[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9};
int hash_table[10000005] = {};

int getPhone(void){
	int result = 0, c ;
	while( (c = getchar()) != 10 ){
		if(c==45||c==32)
			continue;

		result *= 10;
		if(c>=65 && c<=90){
			result += pad[c-65];
		}else{
			result += c-48;
		}
	}
	return result;
}

void quicksort( int start, int end, int array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ )
            if( array[i] < array[start] )
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
	freopen("q755.in", "r", stdin);
	freopen("q755.out", "w", stdout);
	#endif

	int caseNum, lineNum, once = 0;
	scanf("%d", &caseNum);
	while(caseNum--){
		memset(hash_table, 0 , sizeof(hash_table));
		int output[100005];
		int top = 0;

		scanf("%d", &lineNum);
		getchar();
		while(lineNum--){
			int tmp = getPhone();
			hash_table[tmp] += 1;
			if(hash_table[tmp] == 2)
				output[top++] = tmp;
		}
		quicksort(0, top, output);
		if(once){
			putchar(10);
		}
		once = 1;


		if(top==0){
			puts("No duplicates.");
		}else{
			int i;
			for(i=0;i<top;i++){
				printf("%03d-%04d %d\n", output[i]/10000, output[i]%10000, hash_table[output[i]]);
			}
		}
	}
	return 0;
}
