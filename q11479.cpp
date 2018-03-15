// 0.004 (c)
#include <stdio.h>

long long int tri[3];

long long int max(long long int inputA, long long int inputB){
	return (inputA > inputB)? inputA : inputB;
}

int valid(void){

	if(tri[0]<= 0 || tri[1] <= 0 || tri[2] <= 0){
			return 0;
	}

	long long int tmp = max( tri[0], max(tri[1], tri[2]) );
	long long int rest = tri[0] + tri[1] + tri[2] - tmp;
    if( tmp < rest ){
        return 1;
    }
    return 0;
}

int main(void){

    int caseNum = 0, currentCase = 0;
    scanf("%d", &caseNum);
    while(currentCase++ < caseNum ){

        scanf("%lld %lld %lld", &tri[0], &tri[1], &tri[2]);
        
        printf("Case %d: ", currentCase);
        if( valid() == 1){
        	   if(tri[0] == tri[1] && tri[1] == tri[2]){
        	               printf("Equilateral\n");
        	     }else if(tri[0] == tri[1] || tri[1] == tri[2] || tri[0] == tri[2]){
						   printf("Isosceles\n");
        	     }else{
        	    	 	   printf("Scalene\n");
        	     }
        }else{
              printf("Invalid\n");
        }

    }
    return 0;
}
