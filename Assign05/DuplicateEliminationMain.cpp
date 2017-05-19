// Filename: DuplicateEliminationMain.cpp
// Description: Asssignment 05 Excercise 7.13 Main class that eliminates
//				duplicated numbers and outputs unique numbers
//
// Version: 1.0
// Created: 02/03/17 11:30AM
// Author: Ronnie Manimtim

#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

const int START_INDEX = 0; // Start of index
const int START_COUNTER = 1; // Start of counter
const int DENOMINATOR_VALUE = 5; // Denomintor value
const int REMAINDER_VALUE = 4; // Remainder value
const int STREAM_SIZE = 6; // Stream space size
const int MAX = 100; // Maximum input range.
const int MIN = 10; // Minimum input range.
const int ARRAY_SIZE = 20; // Maximum array size.

bool isUnique(const int &, const array<int, ARRAY_SIZE>); // Function to confirm unique user input

// Function main begins program execution
int main()
{
	int input = 0; // User input.
	int arrayIndex = -1; // The array position.
	array<int, ARRAY_SIZE> numbers = {}; // Array number storage

	// Loops from 1 to 20 prompt user for valid input
	for (size_t counter = START_COUNTER; counter <= ARRAY_SIZE; counter++)
	{
		cout << "\nEnter # " << counter << " : ";
		cin >> input;

		// While user input is not valid display error message
		while (cin.rdstate() || input > MAX || input < MIN)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cerr << "The number entered is not in the valid range of " << MIN << " to " << MAX << endl;
			cout << "\nEnter # " << counter << " : ";
			cin >> input;
		} // End while

		// If user input is unique display unique message
		if (isUnique(input, numbers))
		{
			numbers[++arrayIndex] = input;

			cout << "The number: " << input << " is unique" << endl;
		} // End if

	} // End for

	cout << "\n\nThe unique numbers are:\n\n";

	// Loops from 0 to 19 outputing unique user input
	for (size_t index = START_INDEX; index <= arrayIndex; index++)
	{
		cout << setw(STREAM_SIZE) << numbers[index];

		// If index divisable by denominator creat new line
		if (index % DENOMINATOR_VALUE == REMAINDER_VALUE)
		{
			cout << '\n';
		} // End if

	} // End for

	cout << '\n' << endl;

	system("pause");
} // End main

// Function to return true if user input is unique otherwise false
bool isUnique(const int &value, const array<int, ARRAY_SIZE> values)
{
	// Loops from 0 to 19 confirming non unique user input
	for (auto index = START_INDEX; index < ARRAY_SIZE; index++)
	{
		// If given value equals stored value return false
		if (value == values[index])
		{
			return false;
		} // End if

	} // End for

	return true;
} // End isUnique