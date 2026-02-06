//Programming Project - Torkkel Juuso


#include <iostream>

#include <Windows.h>

#include <string>

#include <limits>

#include <stdlib.h>

#include <time.h>

#undef max //needed for the GetValidInput() some weird visual studio thing

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
//Distance
float distanceKm;
float miles;
float nauticalMiles;

//Variables for Section4() "Menu"
char selector;

int main()
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	cout << "The program starts:" << endl << endl;

	char choice; 

	while (true) //The lession exercises really helped me understand loops better
	{
		choice = Section4();

		switch (choice) //found someone recomending switch online and tried it out here
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
			cout << endl << "The program ends. Goodbye!" << endl;
			return 0;

		default:
			cout << "You chose... poorly. Try again." << endl << endl;
		}
	}
}

/*I think this qualifies as a rule of thumb:
  Continue program - break
  Exit function - return
  Exit program - return from main*/

//Made this cool function to make sure the given input is of desired type
template <typename T> //First time using templates
void GetValidInput(T& var, const string& prompt)
{
	while (true)
	{
		cout << prompt;
		cin >> var;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ooops... Invalid input. TRY AGAIN!" << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
}

//Use this for Section3()
template <typename T>
void GetValidInputInRange(T& var, const string& prompt, T min, T max)
{
	while (true)
	{
		cout << prompt;
		cin >> var;

		if (cin.fail() || var < min || var > max) //do this so that we get different error messages for each
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Allowed range: " << min << " - " << max << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
}



void Section1()
{
	AskData();

	PrintData();
}

void Section2()
{
	GetValidInput(months, "Number of months you recive study support: ");
	GetValidInput(monthlyAmount, "Monthly amount (€): ");
	yearlySum = monthlyAmount * months;
	cout << "The amount of study support is " << yearlySum << "€ per year." << endl << endl;
}


void Section3()
{
	char choice;

	while (true)
	{
		cout << "1. Count grade" << endl;
		cout << "2. Kilometer to miles converter" << endl;
		cout << "Q. Return to main menu" << endl;

		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice)
		{
		case '1':
		{
			GetValidInputInRange(userGivenScore, "Insert exam points (0–100): ", 0, 100);
			CalculateGrade();
			cout << "Your grade is: " << printedGrade << endl << endl;

			if (userGivenScore == 100)
				cout << "Congratulations! You got full points!" << endl << endl;
			break;
		}

		case '2':
		{
			GetValidInput(distanceKm, "Give distance in kilometers: ");
			ConvertKm();
			break;
		}

		case 'Q':
		case 'q':
			return;

		default:
			cout << "Invalid selection. Try again." << endl << endl;
		}
	}
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

void AskData()
{
	cout << "Please type your information" << endl;

	cout << "Your Name: ";
	cin >> name;

	GetValidInput(age, "Your age: ");
	GetValidInput(studentNumber, "Student number: ");
	GetValidInput(height, "Your height: ");
	GetValidInput(weight, "Your weight: ");

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
	cout << "Your data has been saved... nowhere." << endl << endl;
}

void CalculateGrade()
{
	if (userGivenScore <= 49) 
		printedGrade = 0;
	else if (userGivenScore <= 59) 
		printedGrade = 1;
	else if (userGivenScore <= 69) 
		printedGrade = 2;
	else if (userGivenScore <= 79) 
		printedGrade = 3;
	else if (userGivenScore <= 89) 
		printedGrade = 4;
	else printedGrade = 5;
}


void ConvertKm()
{
	char choice;

	while (true)
	{
		cout << "M - Convert to miles" << endl;
		cout << "N - Convert to nautical miles" << endl;
		cout << "Q - Main menu" << endl;

		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice)
		{
		case 'M':
		case 'm':
			miles = distanceKm * 0.6215f;
			cout << "Distance in miles: " << miles << endl << endl;
			break;

		case 'N':
		case 'n':
			nauticalMiles = distanceKm * 0.5399f;
			cout << "Distance in nautical miles: " << nauticalMiles << endl << endl;
			break;

		case 'Q':
		case 'q':
			return;

		default:
			cout << "Oopsie... Did your finger slip? Try again." << endl << endl;
		}
	}
}


