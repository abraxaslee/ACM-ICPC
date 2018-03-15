//q514.cpp - 2011/09/25
//accepted at 
//run time = 0.088
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main(){

	int n, targetNum;

	caseStart:
	scanf("%d", &n);
	if(n==0){
		return 0;
	}
	while(true){
		stack<int> myStack;
		queue<int> myQueue;
		for(int i=0;i<n;i++){
			scanf("%d", &targetNum);
			if(targetNum==0){
				printf("\n");
				goto caseStart;
			}
			myQueue.push(targetNum);
		}
		for(int i=0;i<n;i++){
			myStack.push(i+1);
				while(!myQueue.empty()&&!myStack.empty()){
				if(myQueue.front()==myStack.top()){
					myStack.pop();
					myQueue.pop();
				}else{
					break;
				}
			}
		}
		if(myQueue.empty()){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
