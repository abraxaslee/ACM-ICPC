//Q458: The Decoder
//q458.cpp - 2011/08/27
//accepted at 2011-08-29 02:58:13
//run time = 0.124

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string inputString;
	while(getline(cin, inputString)){
		for(int i=0;i<inputString.length();i++){
			inputString[i] -= 7;
		}
		cout << inputString <<endl;
	}
	return 0;
}
