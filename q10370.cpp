//q10370.cpp - 2011/09/10
//accepted at 2011-09-10 06:19:49
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	int iCaseNum = 0, totalStudent = 0;

	scanf("%d", &iCaseNum);
	while(iCaseNum > 0){
		scanf("%d", &totalStudent);
		short int studentGrade[1000];
		int totalGrade = 0;
		short int iAboveAvg = 0;
		double dAboveAvg = 0;
		for(int i = 0;i<totalStudent;i++){
			scanf("%d", &studentGrade[i]);
			totalGrade += studentGrade[i];
		}
		for(int i = 0;i<totalStudent;i++){
			if(studentGrade[i]*totalStudent>totalGrade){
				iAboveAvg += 1;
			}
		}
		dAboveAvg = (static_cast<double>(iAboveAvg) / totalStudent)*100;
		printf("%.3f%%\n", dAboveAvg);
		iCaseNum -=1;
	}
	return 0;
}
