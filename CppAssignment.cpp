/*
	Computer Programming I -  Assignment one
	student name  : Lee Yu Hin
	student ID    : 10485746
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//function prototypes
void show_help();
//return input for the employ type
double Manager();
double HourWorker();
double ComissionWorker();
double PieceWorker();

void bubbleSort(int, int, double[], int[]);
void swap(double&, double&);
void swap(int&, int&);

//output the result with non-ascending order
void getResult(double[], int[]);

int main(){

	//local variable initialization
	int employCode; //the empolyee code
	double totalSalary[4] = { 0, 0, 0, 0 }; //the salary of each employee type
	int positionRanking[4] = { 0, 1, 2, 3 }; //the ranking of total salary for each employee type
	bool exitProgram = false; //flag boolean that indicates user exits program

	while(exitProgram == false){

	show_help();
	cin >> employCode;

		switch(employCode){
			//case 1 to 4 : add the returned value of input of corresponding employee type
			case 1:
				totalSalary[0] = totalSalary[0] + Manager();
				break;

			case 2:
				totalSalary[1] = totalSalary[1] + HourWorker();
				break;

			case 3:
				totalSalary[2] = totalSalary[2] + ComissionWorker();
				break;

			case 4:
				totalSalary[3] = totalSalary[3] + PieceWorker();
				break;

			case 5:
				exitProgram = true;
				break;

			default:
				cout << "Invalid input" << endl;
				break;
		}

		cout <<endl;
	}

	bubbleSort(0, 3, totalSalary, positionRanking);
	getResult(totalSalary, positionRanking);

	system("PAUSE");
	return 0;
}

void show_help(){
	//show help message
	cout << "Position" << "\t\t"	<< "Empolyee code" << endl
		 << "Manager"  			<< "\t\t\t" 	<< "1"			  << endl
		 << "Hour Worker"		<< "\t\t" 	<< "2"			  << endl
		 << "Commission Worker" << "\t" 	<< "3"			  << endl
		 << "Piece worker"  	<< "\t\t" 	<< "4"			  << endl
		 << "Exit Program" 		<< "\t\t"		<< "5"			  << endl
		 << endl
		 << "Please enter the employee code :"	  << endl;
	return;
}
double Manager(){
	double fixedSalary;

	cout << "Please enter fixed weekly salary :" << endl;
	cin >> fixedSalary;

	if(fixedSalary < 0){
		cout << "Invalid input" << endl;
		return 0;
	}

	return fixedSalary;
}

double HourWorker(){
	int workedHour, hourlyRate;
	double weeklySalary;

    cout << "Please enter hourly rate :" << endl;
    cin >> hourlyRate;

    cout << "Please enter number of hours worked :" << endl;
    cin >> workedHour;

    if(hourlyRate < 0 || workedHour < 0){
    		cout << "Invalid input" << endl;
    		return 0;
    	}

    //for over-time work, the extra hours are multiplied by 1.5
    if (workedHour <= 40)
    	weeklySalary = hourlyRate * workedHour;
    else
    	weeklySalary = (workedHour-40) *hourlyRate *1.5 + 40*hourlyRate;

    return weeklySalary;
}

double ComissionWorker(){
    double weeklySalary, grossSales;

    cout << "Please enter the gross weekly sales :" << endl;
    cin >> grossSales;

	if(grossSales < 0){
		cout << "Invalid input" << endl;
		return 0;
	}

    weeklySalary = 250 + ( 5.7 /100 * grossSales);
    return weeklySalary;
}

double PieceWorker(){
	double weeklySalary, fixedCommission, amountProduced;

	cout << "Please enter the fixed salary per item produced :" << endl;
	cin >> fixedCommission;

	cout << "Please enter the amount of item produced :" << endl;
	cin >> amountProduced;

	if(fixedCommission < 0 || amountProduced < 0){
		cout << "Invalid input" << endl;
		return 0;
	}

	weeklySalary = fixedCommission * amountProduced;
	return weeklySalary;
}

void bubbleSort(int start, int end, double array[], int pos[]){

    for(int i=start;i<=end;i++)
        for(int k=i+1; k<=end; k++)
            if( array[i] < array[k]){
                swap(array[i], array[k]);
                swap(pos[i], pos[k]);
                }

    return;
}

void swap(double& numberA, double& numberB){
	double temp;
    temp = numberA;
    numberA = numberB;
    numberB = temp;
    return;
}

void swap(int& numberA, int& numberB){
	int temp;
    temp = numberA;
    numberA = numberB;
    numberB = temp;
    return;
}

void getResult(double salary[], int rank[]){
	//char string for position name
	char jobs[4][20] = {
	                     {'M','a','n','a','g','e','r','\t','\t','\0'},
	                     {'H','o','u','r',' ','W','o','r','k','e','r','\t','\0'},
	                     {'C','o','m','m','i','s','s','i','o','n',' ','W','o','r','k','e','r','\0'},
	                     {'P','i','e','c','e',' ','W','o','r','k','e','r','\t','\0'}
	                   };

	cout << "Rank" << "\t\t" << "Position" << "\t\t\t" << "Weekly Salary" << endl;
    for(int k=0;k<4;k++)
       cout << k+1 << "\t\t" << jobs[rank[k]] << "\t\t" << salary[k] << endl;

    cout << "__________________________________________________________" << endl
    	 << "Total Salary for a week:" << "\t\t\t" << salary[0]+salary[1]+salary[2]+salary[3] << endl;
    return;
}
