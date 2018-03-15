// 0.004
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11942.in", "r", stdin);
	freopen("q11942.out", "w", stdout);
	#endif

	int caseNum, length, lengthLast, ascent, descent, i;
	scanf("%d", &caseNum);
	printf("Lumberjacks:\n");
	while(caseNum-- > 0){
		ascent = 0, descent = 0;
		scanf("%d%d", &lengthLast, &length);

		if(lengthLast < length){
			ascent = 1;
		}else if(lengthLast > length){
			descent = 1;
		}
		for(i=0;i<8;i++){
			lengthLast = length;
			scanf("%d", &length);
			if(ascent+descent == 0){
				continue;
			}else if(descent==1){
				if(lengthLast<length){
					descent = 0;
				}
			}else if(ascent==1){
				if(lengthLast>length){
					ascent = 0;
				}
			}
		}
		if(ascent+descent==0){
			printf("Unordered\n");
		}else{
			printf("Ordered\n");
		}
	}
	return 0;
}
