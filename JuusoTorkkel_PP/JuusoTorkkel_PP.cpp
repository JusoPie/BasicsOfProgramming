//Programming Project - Torkkel Juuso


#include <iostream>

#include <Windows.h>

#include <string>

#include <limits>

#include <stdlib.h>

#include <time.h>

#include <chrono>

#include <cmath>

#include <array>

#include <fstream>

#include <list>

#undef max //needed for the GetValidInput() some weird visual studio thing

using namespace std;

//Functions
void Section1();
void Section2();
void Section3();
char Section4();
void Section5();
void Section6();
void Section7();
void Section8();
void Section9();
void Section10();
void TuntiTehtävä5();
void AskData();
void PrintData();
void CalculateGrade();
void ConvertKm();
void AnalyzeSentence(string sentence);
int Odds(int arr[], int size);
int Evens(int arr[], int size);
int Positives(int arr[], int size);
int Negatives(int arr[], int size);
int HowManyZeros(int arr[], int size);


//All variables are global unless there were some errors

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

	cout << "Welcome!" << endl << endl;

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

		case '6':
			Section6();
			break;

		case '7':
			Section7();
			break;

		case '8':
			Section8();
			break;

		case '9':
			Section9();
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
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //I use this line often. Fixes an issue of many given characters triggering the menus multiple times
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

		if (cin.fail() || var < min || var > max)
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


//Basic stuff
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

//Here im using the same kind of selection method like in Main()
void Section3()
{
	char choice;

	while (true)
	{
		cout << "1. Count grade" << endl;
		cout << "2. Kilometer to miles converter" << endl;
		cout << "Q. Main menu" << endl;

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

		case 'Q': //can prompt q or Q
		case 'q':
			return;

		default:
			cout << "Invalid selection. Try again." << endl << endl;
		}
	}
}

//The menu
char Section4()
{
	char selector;

	cout << "Main Menu" << endl << endl;
	cout << " 1. User information" << endl;
	cout << " 2. Study support" << endl;
	cout << " 3. Convert score and miles" << endl;
	cout << " 4. Help" << endl;
	cout << " 5. Prime numbers" << endl;
	cout << " 6. Randomizer" << endl;
	cout << " 7. Sentence analyzer" << endl;
	cout << " 8. Reserve your seat" << endl;
	cout << " 9. Number type analyzer" << endl;
	cout << " Q - Quit" << endl;
	cin >> selector;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return selector;
}

//This method works bechause you return to the menu everytime after trying
void Section5() 
{
	//Variables for Section5()
	int numb;
	bool isPrime = true;

	GetValidInputInRange(numb, "Give a positive number other than 1: ", 2, 999999999); //Unconventional maybe

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

void Section6() 
{
	using namespace std::chrono; //when I declared this after the includes it gave an error to the int months in section2()

	//something between 50000 and 100000
	int rnd = (rand() % 50001) + 50000;

	auto start_time = high_resolution_clock::now();

	//print 50,000 - 100,000 random characters form a to z
	for (int i = 0; i < rnd; i++) {

		char randomCharacter = 'a' + rand() % 26;

		cout << randomCharacter;
	}

	auto end_time = high_resolution_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(end_time - start_time);

	cout << "\n\nLoop took " << time_span.count() << " seconds.\n"; 
	//forgot that i can use \n to do a linebreak so I reminded myself here
}

void Section7()
{
	string input;
	cout << "Enter a sentence: ";
	getline(cin, input);

	AnalyzeSentence(input);
}

void Section8()
{
	const int ROWS = 10;
	const int SEATS = 20;

	string seats[ROWS][SEATS];

	//Draw the layout of the seats
	cout << "---------- Movie Theater Seating ----------\n\n";

	for (int i = 0; i < ROWS; i++)
	{
		cout << "Row " << setw(2) << i + 1 << ": ";  // pad row numbers
		for (int a = 0; a < SEATS; a++)
		{
			//Store seat number as two-character string for alignment
			seats[i][a] = (a + 1 < 10 ? " " : "") + to_string(a + 1);
			cout << setw(3) << seats[i][a];
		}
		cout << endl << endl;
	}

	//Ask for a row and a seat
	int inputRow, inputSeat;
	GetValidInputInRange(inputRow, "Choose row: ", 1, ROWS);
	GetValidInputInRange(inputSeat, "Choose seat: ", 1, SEATS);

	//Mark the seat
	seats[inputRow - 1][inputSeat - 1] = "XX";

	//Redraw the seating layout
	cout << "\n---------- Updated Seating Chart ----------\n\n";

	for (int i = 0; i < ROWS; i++)
	{
		cout << "Row " << setw(2) << i + 1 << ": ";
		for (int a = 0; a < SEATS; a++)
		{
			cout << setw(3) << seats[i][a];
		}
		cout << endl << endl;
	}

}

void Section9()
{
	//declarations
	int num;
	int arr[40];
	int min = -10, max = 10;

	//print 40 random numbers from -10 to 10
	for (int i = 0; i < 40; i++) {
		num = (rand() % (max - min + 1)) + min; //TODO: change to more random. now the first run is always the same.
		arr[i] = num;
		cout << num << endl;
	}

	//Call the counting functions and print the counts
	cout << "Odd: " << Odds(arr, 40) << endl;
	cout << "Even: " << Evens(arr, 40) << endl;
	cout << "Positive: " << Positives(arr, 40) << endl;
	cout << "Negative: " << Negatives(arr, 40) << endl;
	cout << "Zero: " << HowManyZeros(arr, 40) << endl;

	
}

void Section10()
{
	//if user.dat exists--load user data from user.dat
	//else--create user.dat
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

void AnalyzeSentence(string sentence) {
	int characters = 0;
	int clauses = 1; // There is always at least one clause

	//leave out spaces and tab
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] != ' ' && sentence[i] != '\t')
			characters++;
	}

	// Check clause indicators
	string conjunctions[] = {
		" and ", " but ", " or ", " because ",
		" although ", " while ", " if ", " when "
	};

	for (int i = 0; i < 8; i++) {
		size_t pos = sentence.find(conjunctions[i]);
		while (pos != string::npos) {
			clauses++;
			pos = sentence.find(conjunctions[i], pos + 1);
		}
	}

	// Also count colons and semicolons
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ',' || sentence[i] == ';')
			clauses++;
	}

	cout << "Character count: " << characters << endl;

	if (clauses == 1) {
		cout << "Simple sentence" << endl;
	}
	else {
		cout << "Compound/Complex sentence" << endl;
		cout << "Number of clauses: " << clauses << endl;
	}
}

int Odds(int arr[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 != 0)
			count++;
	return count;
}

int Evens(int arr[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 0)
			count++;
	return count;
}

int Positives(int arr[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] > 0)
			count++;
	return count;
}

int Negatives(int arr[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] < 0)
			count++;
	return count;
}

int HowManyZeros(int arr[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] == 0)
			count++;
	return count;
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
	if (userGivenScore <= 49) printedGrade = 0;
	else if (userGivenScore <= 59) printedGrade = 1;
	else if (userGivenScore <= 69) printedGrade = 2;
	else if (userGivenScore <= 79) printedGrade = 3;
	else if (userGivenScore <= 89) printedGrade = 4;
	else printedGrade = 5;
	//No unnecessary lines
}


void ConvertKm()
{
	char choice;

	while (true)
	{
		cout << "M - Convert to miles" << endl;
		cout << "N - Convert to nautical miles" << endl;
		cout << "Q - Cancel" << endl;

		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice)
		{
		case 'M':
		case 'm':
			miles = distanceKm * 0.6215f; //Confirmed by the internet
			cout << "Distance in miles: " << miles << endl << endl;
			break;

		case 'N':
		case 'n':
			nauticalMiles = distanceKm * 0.5399f; //Confirmed by the internet
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


