//q501v2.cpp - 2012/01/01
//accepted at 
//run time = 
#include <stdio.h>
#include <iterator>
#include <set>
using namespace std;

int buff[30005];

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q501.in", "r", stdin);
	freopen("q501.out", "w", stdout);
	#endif

	int caseNum, top, cmd, tmp, i, cnt, pos, ans;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d%d", &top, &cmd);
		for(i=0; i<top; ++i)
			scanf("%d", &buff[i]);

		multiset<int> box;
		multiset<int>::iterator iter;
		ans = cnt = pos = i = 0;

		while(cmd--){
			scanf("%d", &tmp);
			while(i < tmp){
				if(buff[i] < ans)
					pos--;

				box.insert(buff[i++]);
			}
			iter = box.begin();
			advance(iter, cnt+pos);
			ans = *(iter);
			printf("%d\n", ans);
			cnt += 1;
		}
		putchar(10);
	}
	return 0;
}
