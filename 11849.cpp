//2012/02/27
//11849.cpp
//Run time: 1.836

#include <cstdio>
#include <map>
using namespace std;
int main(){

	#ifndef ONLINE_JUDGE
	freopen("11849.in", "r", stdin);
	freopen("11849.out", "w", stdout);
	#endif

	int N, M, temp, ans;
	while(scanf("%d%d", &N, &M) == 2){
		if(N + M == 0)	break;
		map<int, bool> CD;
		ans = 0;
		while(N--){
			scanf("%d", &temp);
			CD[temp] = true;
		}
		while(M--){
			scanf("%d", &temp);
			if(CD[temp] == true)
				++ans, CD[temp] = false;
		}
		printf("%d\n", ans);
	}
	return 0;
}
