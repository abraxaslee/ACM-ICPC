//Q494: Kindergarten Counting Game
//q494.cpp - 2011/08/29
//accepted at 2011-08-29 05:03:38
//run time = 0.012

#include <iostream>
#include <cstring>
using namespace std;

inline bool ifWords(char);
int main(){
	string inputString;
	int wordsNum;
	while(getline( cin, inputString)){
		wordsNum = 0;
		for(int i=0;i<inputString.length();i++){
			if(!ifWords(inputString[i+1])){
				if(ifWords(inputString[i])){
					wordsNum++;
				}
			}
		}
		cout << wordsNum << endl;
	}
	return 0;
}

inline bool ifWords(char inChar){

	if((inChar >=65&&inChar<=90 )||( inChar>=97&&inChar<=122)){
		return true;
	}else{
		return false;
	}
	return false;
}
