//q10107v2.cpp - 2011/09/04
//algorithm: insertion sort
//accepted at 2011-09-04 09:28:57
//run time = 0.032
#include <stdio.h>
using namespace std;

int main(){
	int myArray[10000];
	int inputNum = 0;
	int arrayLength = 0;
	int i = 0;

	while(scanf("%d", &inputNum)!=EOF){
	//debug usage
		/*
		if(inputNum==0){
			for(int j=0;j<arrayLength;j++){
				printf("myArray[%d] = %d\n", j, myArray[j]);
			}
			continue;
		}*/

		i=arrayLength;
		while(i>0){
			i--;
			if(inputNum<myArray[i]){
				myArray[i+1] = myArray[i];
			}else{
				i++;
				break;
			}
		}
		myArray[i] = inputNum;
		arrayLength += 1;
		if(arrayLength%2){
				printf("%d\n",myArray[((arrayLength+1)/2)-1]);
			}else{
				printf("%d\n", (myArray[((arrayLength)/2)-1]+myArray[((arrayLength)/2)])/2);
		}


	}
	return 0;
}
