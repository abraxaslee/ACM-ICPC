//q11059.cpp - 2011/09/25
//accepted at 2011-09-25 13:45:39
//run time = 0.008
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n, temp, caseNum=0;

	while(scanf("%d", &n)!=EOF){
		caseNum += 1;
		int top=0;
		int i=0;
		double myArray[18] = {0};
		bool positive[18] = {false};
		bool negative[18] = {false};
		while(n-- >0){

			scanf("%d", &temp);
			if(temp==0){
				if(myArray[i]!=0&&n!=0){
					i+=2;
				}else{
					i+=1;
				}
			}else if(temp > 0){

				if(negative[i] == true){
					i++;
				}

				if(myArray[i]==0){
					myArray[i] = temp;
				}else{
					myArray[i] *= temp;
				}
				positive[i] = true;


			}else if(temp < 0){
				if(positive[i]==true||negative[i]==true){
					i++;
				}
				myArray[i] = temp;
				negative[i] = true;
			}
		}
		if(myArray[i]==0){
			top = i;
		}else{
			top = i+1;
		}

		double productTemp;
		double maxP = 0;
		for(int j=0;j<top;j++){
			productTemp = myArray[j];
			for(int z=j+1;z<top;z++){
				maxP = max(maxP,productTemp);
				productTemp *= myArray[z];
			}
			maxP = max(maxP,productTemp);
		}
		printf("Case #%d: The maximum product is %.0f.\n\n", caseNum, maxP);

	}
	return 0;
}
