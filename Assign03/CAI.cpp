// Filename:  CAIMain.cpp
// Description:  Asssignment 03 Main class that wiil 
//				 ask random multiplication questions
//
// Version:  1.0
// Created:  02/01/17 04:10PM
// Author:  Ronnie Manimtim

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void correctMessage(); // Outputs correct message randomly
void incorrectMessage(); // Outputs incorrect message randomly
void multiplication(); // Randomly generate two numbers that need to be multiplied

int answer;
int solution;
int firstNumber;
int secondNumber;

const int EXIT = -1;
const int NUMBER_SCALING_FACTOR_VALUE = 10;
const int MESSAGE_SCALING_FACTOR_VALUE = 4;

// Function main begins program execution
int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	firstNumber = (rand() % NUMBER_SCALING_FACTOR_VALUE);
	secondNumber = (rand() % NUMBER_SCALING_FACTOR_VALUE);

	cout << "Enter -1 to End." << endl;
	cout << "How much is " << firstNumber << " times " << secondNumber << " (-1 to End)? ";
	cin >> answer;

	solution = firstNumber * secondNumber;

	multiplication();

	cout << "\nThat's all for now. Bye." << endl;

	system("pause");

} // End main

  // Outputs correct message randomly
void correctMessage()
{
	string correct[]{ "Very good!", "Excellent!", "Nice work!", "Keep up the good work!" };

	cout << correct[rand() % MESSAGE_SCALING_FACTOR_VALUE] << endl;

} // End correctMessage()

  // Outputs incorrect message randomly
void incorrectMessage()
{
	string incorrect[]{ "No. Please try again.", "Wrong. Try once more.", "Don't give up!", "No. Keep trying." };

	cout << incorrect[rand() % MESSAGE_SCALING_FACTOR_VALUE] << endl;

} // End incorrectMessage()

  // Randomly generate two numbers that need to be multiplied
  // while the answer does not equal EXIT 
void multiplication()
{
	// Continue to loop if does not equal EXIT
	while (answer != EXIT)
	{
		// Answer correct? Output correct message
		// and ask another multiplication question
		if (answer == solution)
		{
			correctMessage();

			srand(static_cast<unsigned int>(time(NULL)));
			firstNumber = (rand() % NUMBER_SCALING_FACTOR_VALUE);
			secondNumber = (rand() % NUMBER_SCALING_FACTOR_VALUE);

			cout << "\nHow much is " << firstNumber << " times " << secondNumber << " (-1 to End)? ";
			cin >> answer;

			solution = firstNumber * secondNumber;
		}
		else if (cin.fail()) // Output invalid input message
		{
			cin.clear();
			cin.ignore();

			cout << "Invalid input entered - try again: ";
			cin >> answer;
		}
		else // Output incorrect message until it is correct
		{
			incorrectMessage();

			cout << "? ";
			cin >> answer;
		}

	} // End while (answer != -EXIT)

} // End multiplication()