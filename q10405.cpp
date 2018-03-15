//run time = 0.060
#include <stdio.h>
#include <string.h>

char buff[2][1005];
int dp[1005][1005] = {};

int max(int A, int B){   
    return A>B ? A:B;
}


int main(){
    
   freopen("q10405.in","r",stdin);
   freopen("q10405.out","w",stdout);
   int i, j;
   
   while(gets(buff[0])){
       gets(buff[1]);
       memset (dp,0,sizeof(dp));
       for(i=0;buff[0][i]!='\0'; ++i){
          for(j=0;buff[1][j]!='\0'; ++j){
             if(buff[0][i] == buff[1][j])
                dp[i+1][j+1] = dp[i][j] +1;
             else
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
          }
       }

       printf("%d\n", dp[i][j]);
    }

   return 0;   
}
