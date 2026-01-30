//Programming Project - Torkkel Juuso


#include <iostream>

#include <Windows.h>

#include <string>

using namespace std;

//In C/C++ programs, functions must be declared before they are called
void Section1();
void Section2();
void Section3();
void TuntiTehtävä5();
void AskData();
void PrintData();
void CalculateGrade();
void ConvertKm();

//Variables for Section1()
string name;
int age;
int studentNumber;
float height;
float weight;

//Variables for Section2()
int months;
float monthlyAmount;
float yearlySum;

//Variables for Section3()
//Grade
int userGivenScore;
int printedGrade;
int fork;
//Distance
float distanceKm;
float miles;
float nauticalMiles;
char userChar;


int main()
{
	//Special characters (ä, ö, ü, etc.)
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	cout << "The program starts:" << endl << endl;

	

	//Section2();

	//Section1();

	Section3();

	//TuntiTehtävä5();

	cout << endl << "The program ends and shuts down automatically." << endl;
}


void Section1()
{
	AskData();

	PrintData();
}

void Section2()
{
	cout << "Enter the number of months you recive study support for this year" << endl;
	cout << "Number of months:";
	cin >> months;
	cout << "What is the amount of monthly support? (123.45)" << endl;
	cout << "Amount:";
	cin >> monthlyAmount;
	cout << "Thank you!" << endl << endl;
	yearlySum = monthlyAmount * months;
	cout << "The amount of study support is " << yearlySum << "€ per year." << endl << endl;
}

void Section3()
{
	cout << "Count grade input 1" << endl;
	cout << "Kilometer converter input 2" << endl;
	cout << "Input: ";
	cin >> fork;
	
	if (fork == 1) {
		cout << "Insert exam points (0-100) and you will recive a grade" << endl;
		cout << "Score:";
		cin >> userGivenScore;
		CalculateGrade();
		cout << "Your grade is: " << printedGrade << endl;
		if (userGivenScore == 100) {
			cout << "Congratulations! You got full points!" << endl << endl;
		}
	}
	
	if (fork == 2) {
		cout << "Give distance in kilometers" << endl;
		cout << "Distance: ";
		cin >> distanceKm;
		ConvertKm();
	}

	else {
		Section3();
	}
}

void TuntiTehtävä5() {

}

void AskData()
{
	cout << "Please type your information" << endl;
	cout << "Your Name:";
	cin >> name;
	cout << "Your age:";
	cin >> age;
	cout << "Student number:";
	cin >> studentNumber;
	cout << "Your height:";
	cin >> height;
	cout << "Your weight:";
	cin >> weight;
	cout << endl << "Thank you!" << endl << endl;
}

void PrintData()
{
	cout << "The information you have given:" << endl;
	cout << "Your name:" << name << endl;
	cout << "Your age:" << age << endl;
	cout << "Your student number:" << studentNumber << endl;
	cout << "Your height:" << height << endl;
	cout << "Your weight:" << weight << endl << endl;
	cout << "Your data has been saved to... nowhere." << endl << endl;
}

void CalculateGrade()
{
	if (userGivenScore >= 0 && userGivenScore <= 49){
		printedGrade = 0;
	}

	if (userGivenScore >= 50 && userGivenScore <= 59) {
		printedGrade = 1;
	}

	if (userGivenScore >= 60 && userGivenScore <= 69) {
		printedGrade = 2;
	}

	if (userGivenScore >= 70 && userGivenScore <= 79) {
		printedGrade = 3;
	}

	if (userGivenScore >= 80 && userGivenScore <= 89) {
		printedGrade = 4;
	}

	if (userGivenScore >= 90 && userGivenScore <= 100) {
		printedGrade = 5;
	}

	if (userGivenScore < 0 || userGivenScore > 100) {
		Section3();
	}


}

void ConvertKm()
{
	cout << "Convert to miles input M" << endl;
	cout << "Convert to nautical miles input N" << endl;
	cout << "Quit input Q" << endl;
	cout << "Input: ";
	cin >> userChar;

	if (userChar == 'M' || userChar == 'm') {
		miles = distanceKm * 0.6215;
		cout << "Distance in miles: " << miles << endl;
	}

	if (userChar == 'N' || userChar == 'n') {
		nauticalMiles = distanceKm * 0.5399;
		cout << "Distance in nautical miles: " << nauticalMiles << endl;
	}

	if (userChar == 'Q' || userChar == 'q') {
		//exit here
	}
}

