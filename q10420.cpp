//q10420.cpp - 2011/10/19
//accepted at 2011/12/11
//run time = 0.008
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

char buff[1000];
char home[100];
int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10420.in", "r", stdin);
	freopen("q10420.out", "w", stdout);
	#endif

	map<string, int> mylove;
	map<string, int>::iterator iter;
	int name;
	scanf("%d", &name); getchar();
	while(name--){
		gets(buff);
		sscanf(buff, "%s", home);
		iter = mylove.find(home);
		if(iter != mylove.end())
			iter->second += 1;
		else
			mylove.insert(pair<string, int>(home, 1));
	}

	for(iter = mylove.begin(); iter != mylove.end(); ++iter)
		cout << (*iter).first << " " << (*iter).second << endl;

	return 0;
}
