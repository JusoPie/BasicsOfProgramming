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

int main()
{
	//Special characters (ä, ö, ü, etc.)
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	cout << "The program starts:" << endl << endl;

	

	Section2();

	Section1();

	Section3();

	TuntiTehtävä5();

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
	cout << "Thank you!" << endl;
	yearlySum = monthlyAmount * months;
	cout << "The amount of study support is " << yearlySum << "€ per year." << endl << endl;
}

void Section3()
{

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



