//2012/03/14
//10801.cpp
//Run time: 0.008

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define INF 0x1F1F1F1F
using namespace std;

char buff[1000];
bool lift[5][100];
int dis[5][100];
int speed[5];
int N, K;

typedef struct nodes{
	int level, lift, sec;

	nodes(int nlevel, int nlift, int nsec){
		level = nlevel;
		lift = nlift;
		sec = nsec;
	}

} level;

bool operator<(const level &a, const level &b) {
		return b.sec < a.sec;
};

int abss(int x){
	if(x < 0)	return -x;
	return x;
}

int dijkstra(){
	static int i, next, current, limit;
	static level T(0, 0, 0);
	priority_queue<level> Q;

	for(i=0; i<N; ++i)
		if(lift[i][0] == true)
			Q.push(level(0, i, 0));


	while( !Q.empty() ){
		T = Q.top(); Q.pop();

		if(T.level == K)	return T.sec;

		for(i=0; i<100; ++i){
			if(lift[T.lift][i]){
				next = T.sec + speed[T.lift] * abss( T.level - i);
				if(dis[T.lift][i] > next){
					dis[T.lift][i] = next;
					Q.push(level( i, T.lift, next ));
				}
			}
		}

		for(i=0; i<N; ++i)
			if(lift[i][T.level]){
				next = T.sec + 60;
				if(dis[i][T.level] > next){
					dis[i][T.level] = next;
					Q.push( level(T.level, i, next) );
				}
			}

	}

	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10801.in", "r", stdin);
	freopen("10801.out", "w", stdout);
	#endif

	int i, z, ANS;
	char *token;
	while(scanf("%d%d", &N, &K) == 2){

		for(i=0; i<N; ++i)
			scanf("%d", &speed[i]);

		getchar();


		for(i=0; i<N; ++i){
			memset(dis[i], 0x1f, sizeof(dis[i]));
			gets(buff);
			for(token = strtok(buff, " "); token != NULL; token = strtok(NULL, " "))
				lift[i][atoi(token)] = true;
		}

		ANS = dijkstra();
		if(ANS < 0)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", ANS);

		memset(lift, 0, sizeof(lift));


	}

	return 0;
}
