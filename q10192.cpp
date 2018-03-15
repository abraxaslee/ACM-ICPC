//q10192.cpp - 2011/11/29
//accepted at 
//run time = 0.004
#include <stdio.h>

char buff[2][105];

int max(int A, int B){
    return A>B ? A:B;
}


int main(){

   int i, j, currentCase = 0;

   while(gets(buff[0])){
	   if(buff[0][0] == '#')	break;
       gets(buff[1]);
       int dp[105][105] = {};
       for(i=0;buff[0][i]!='\0'; ++i){
          for(j=0;buff[1][j]!='\0'; ++j){
             if(buff[0][i] == buff[1][j])
                dp[i+1][j+1] = dp[i][j] +1;
             else
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
          }
       }

       printf("Case #%d: you can visit at most %d cities.\n", ++currentCase, dp[i][j]);
    }

   return 0;
}
