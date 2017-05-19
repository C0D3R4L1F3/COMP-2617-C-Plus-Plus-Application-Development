  // Filename:  CAIMain.cpp
  // Description:  Asssignment 03 Main class that wiil 
  //			   ask random multiplication questions
  //
  // Version:  1.0
  // Created:  02/01/17 04:10PM
  // Author:  Ronnie Manimtim

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void correctMessage(); // Outputs correct message randomly
void incorrectMessage(); // Outputs incorrect message randomly
void multiplication(); // Randomly generate two numbers that need to be multiplied

const int EXIT = -1;
const int MULTIPLICATION_RANGE = 10;
const int MESSAGE_RANGE = 4;

// Function main begins program execution
int main()
{
	cout << "Enter -1 to End." << endl;

	multiplication();

	cout << "That's all for now. Bye." << endl;

	system("pause");

} // End main

// Randomly generate two numbers that need to be multiplied
// while the answer does not equal EXIT 
void multiplication()
{
	int answer = 0; // Holds user input
	int solution = 0; // Holds correct answer to equation
	unsigned int firstNumber = 0; // First random number
	unsigned int secondNumber = 0; // Second random number

	// Use current time as seed for random generator 
	srand(time(NULL));

	// Continue to prompt user if answer does not equal -1
	while (answer != EXIT)
	{
		// Generates random numbers between 0-9
		firstNumber = (rand() % MULTIPLICATION_RANGE);
		secondNumber = (rand() % MULTIPLICATION_RANGE);

		// Holds the solution of the equation for user to answer
		solution = firstNumber * secondNumber;

		cout << "How much is " << firstNumber << " times " << secondNumber << " (-1 to End)? ";
		cin >> answer;

		// Output incorrect message until it is correct
		while (answer != EXIT && solution != answer)
		{
			// Invalid input message
			if (cin.fail())
			{
				cin.clear(); // Clear bad input flags
				cin.ignore(INT_MAX, '\n'); // Discard input

				cout << "Invalid input entered - try again: ";
				cin >> answer;
			}
			else // Incorrect answer message
			{
				incorrectMessage();

				cout << "? ";
				cin >> answer;
			} // End if (cin.fail())

		} // End while (answer != -1 && solution != answer)

		// Answer correct? Output correct message
		if (answer != EXIT)
		{
			correctMessage();
		} // End if (answer != EXIT)

		cout << endl;

	} // End while (answer != -EXIT)

} // End multiplication()

// Outputs correct message randomly
void correctMessage()
{
	// Generates a random number between 0-3
	unsigned int correctMessage = rand() % MESSAGE_RANGE;

	switch (correctMessage)
	{
	case 0:
		cout << "Very Good!" << endl;
		break;
	case 1:
		cout << "Excellent!" << endl;
		break;
	case 2:
		cout << "Nice work!" << endl;
		break;
	case 3:
		cout << "Keep up the good work!" << endl;
		break;
	default:
		break;
	} // End switch

} // End correctMessage()

// Outputs incorrect message randomly
void incorrectMessage()
{
	// Generates a random number between 0-3
	unsigned int incorrectMessage = rand() % MESSAGE_RANGE;

	switch (incorrectMessage)
	{
	case 0:
		cout << "No. Please try again." << endl;
		break;
	case 1:
		cout << "Wrong. Try once more." << endl;
		break;
	case 2:
		cout << "Don't give up!" << endl;
		break;
	case 3:
		cout << "No. Keep trying." << endl;
		break;
	default:
		break;
	} // End switch

} // End incorrectMessage()