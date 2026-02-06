//Programming Project - Torkkel Juuso


#include <iostream>

#include <cstdlib> //Found that this library contains exits

#include <Windows.h>

#include <string>

#include <limits>

#include <stdlib.h>

#include <time.h>

#undef max

using namespace std;

//In C/C++ programs, functions must be declared before they are called
//Did not know that. A good reminder that I need more knowledge in baseline coding
void Section1();
void Section2();
void Section3();
char Section4(); //Haven't used a function with this type before.. Facinating
void Section5();
void TuntiTehtävä5();
void AskData();
void PrintData();
void CalculateGrade();
void ConvertKm();
void EndProgram();

//Maybe a bad habbit of declaring all variables here


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
string fork;
//Distance
float distanceKm;
float miles;
float nauticalMiles;
string userChar; 

//Variables for Section4() "Menu"
char selector;

int main()
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	cout << "The program starts:" << endl << endl;

	char choice; 

	while (true) //The lession exercises really helped me finaly understand loops
	{
		choice = Section4();

		switch (choice) //found someone recomending switch online
		{
		case '1':
			Section1();
			break;

		case '2':
			Section2();
			break;

		case '3':
			Section3();
			break;

		case '4':
			cout << "You need help!" << endl << endl;
			cout << "Helpful hint:" << endl;
			cout << " Remember to press Enter after typing your choice." << endl << endl;
			break;

		case '5':
			Section5();
			break;

		case 'Q': //Figured out that when we find a match here we just continue executing
		case 'q':
			cout << endl << "The program ends and shuts down automatically." << endl;
			return 0;

		default:
			cout << "Invalid selection!" << endl << endl;
		}
	}
}

/*I think this qualifies as a rule of thumb:
  Continue program - break
  Exit function - return
  Exit program - return from main*/

void Section1()
{
	AskData();

	PrintData();
}

void Section2()
{
	cout << "Enter the number of months you recive study support for this year" << endl;
	while (true) 
	{
		cout << "Number of months:";
		cin >> months;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		
	}

	while (true)
	{
		cout << "What is the amount of monthly support? (123.45)" << endl;
		cout << "Amount:";
		cin >> monthlyAmount;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	cout << "Thank you!" << endl << endl;
	yearlySum = monthlyAmount * months;
	cout << "The amount of study support is " << yearlySum << "€ per year." << endl << endl;
	
}

void Section3() //Here I use a string to check the choice
{
	cout << "1. Count grade" << endl;
	cout << "2. Kilometer to miles converter" << endl;
	cin >> fork;
	
	if (fork == "1") {
		while (true)
		{
			cout << "Insert exam points (0-100) and you will recive a grade" << endl;
			cout << "Score:";
			cin >> userGivenScore;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input" << endl;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		
		CalculateGrade();

		cout << "Your grade is: " << printedGrade << endl << endl;
		if (userGivenScore == 100) {
			cout << "Congratulations! You got full points!" << endl << endl;
		}
		return;
	}
	
	if (fork == "2") {
		while (true)
		{
			cout << "Give distance in kilometers" << endl;
			cout << "Distance: ";
			cin >> distanceKm;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input" << endl;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		
		ConvertKm();
	}

	else {
		cout << "invalid input" << endl;
		Section3();
	}

	return;
}

char Section4()
{
	char selector;

	cout << "Main Menu" << endl << endl;
	cout << " 1. User information" << endl;
	cout << " 2. Study support" << endl;
	cout << " 3. Convert score and miles" << endl;
	cout << " 4. Help" << endl;
	cout << " 5. Prime numbers" << endl;
	cout << " Q - Quit" << endl;
	cin >> selector;

	return selector;
}

void Section5() 
{
	//Variables for Section5()
	int numb;
	bool isPrime = true;

	cout << "Give a positive number other than 1" << endl;
	cout << "Number: ";
	cin >> numb;

	if (numb <= 1) {
		isPrime = false;
	}
	else {
		for (int i = 2; i < numb; i++) {
			if (numb % i == 0) {
				isPrime = false;
				break;
			}
		}
	}

	if (isPrime) {
		cout << numb << " is a prime number." << endl << endl;
	}
	else {
		cout << numb << " is NOT a prime number." << endl << endl;
	}

	
}

void TuntiTehtävä5() {

	//While, do ..While

	/*float comparison;
	float factor;
	float result;
	float num = 1;
	cout << "Give a positive number: ";
	cin >> comparison;
	cout << "Give a factor: ";
	cin >> factor;
	do
	{
		result = num * factor;
		cout << result << endl;
		num = result;
	} while ( result <= comparison);*/



	/*int num;
	int howManyCharsLong = 0;
	cout << "Give a number:" << endl;
	cin >> num;
	while (num > 0) {
		howManyCharsLong++;
		num /= 10;
	}
	cout << "The number has " << howManyCharsLong << " characters";*/
	
	/*int num = -1;
	while (num < 6) {
		num++;
		if(num == 3 || num == 5){
			continue;
		}
		cout << num << endl;
	}*/

	/*int input;
	cout << "Give any number but (5)" << endl;
	cin >> input;
	while (input != 5) {
		cout << "Give any number but (5)" << endl;
		cin >> input;
	}
	cout << "Stop that!" << endl;*/

	/*int posNum;
	int num;
	cout << "Enter a positive number greater than 1" << endl;
	cout << "Number: ";
	cin >> posNum;
	num = 1;
	while (num <= posNum) {
		cout << num++ << endl;*/
	

}

void AskData() //Here I use cin.Fail to validate the user input. I tried to make a function of it but failed horribly.
{
	cout << "Please type your information" << endl;
	cout << "Your Name:";
	cin >> name;
	while (true) {
		cout << "Your age:";
		cin >> age;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	while (true) {
		cout << "Student number:";
		cin >> studentNumber;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	while (true) {
		cout << "Your height:";
		cin >> height;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	while (true) {
		cout << "Your weight:";
		cin >> weight;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
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
		cout << "You can't have less than 0 or more than 100 points.. Nice try!" << endl << endl;
		Section3();
	}


}

void ConvertKm()
{
	cout << "M - Convert to miles" << endl;
	cout << "N - Convert to nautical miles" << endl;
	cout << "Q - Quit input" << endl;
	cin >> userChar;

	if (userChar == "M" || userChar == "m") {
		miles = distanceKm * 0.6215;
		cout << "Distance in miles: " << miles << endl;
	}

	if (userChar == "N" || userChar == "n") {
		nauticalMiles = distanceKm * 0.5399;
		cout << "Distance in nautical miles: " << nauticalMiles << endl;
	}

	if (userChar == "Q" || userChar == "q") {
		return;
	}

	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input" << endl;
	}
}

void EndProgram()
{
	cout << endl << "The program ends and shuts down automatically." << endl;
	exit(0); // Immediately ends the program
}

