// Filename:  RomanToArabicMain.cpp
// Description:  Asssignment 02 Main class that converts 
//				 Roman Numerals to Hindu Arabic Numerals
//
// Version:  1.0
// Created:  25/01/17 08:00PM
// Author:  Ronnie Manimtim

#include <iostream>
#include <cctype>  // Required for toupper() function

using namespace std;

// Define global const values

const int NUMBER_OF_VALUES = 10;
const int LARGE_VALUE = 100000000;

int main()
{

	cout << NUMBER_OF_VALUES << " Roman numeral values will be input and converted into\n";
	cout << "their equivalent Hindu-Arabic numeric values.\n";

	char nextChar;  // used to input next character

	// Perform loop NUMBER_OF_VALUES times
	for (int i = 1; i <= NUMBER_OF_VALUES; ++i)
	{

		cout << "\nInput Roman numeral # " << i << ": ";  // Output new line and test data number

		int previousValue = LARGE_VALUE; // last value added to sum
		int sum = 0;  // Will be used to represent Hindu-Arabic numeric value
		bool lastCharValid = true; // Set to false when invalid character encountered
		int value = 0; // value of the roman numeral letter

		nextChar = cin.get(); // Input first digit of the next Roman numeral number
		nextChar = toupper(nextChar); // Convert to upper case if not already uppercase

		// Perform loop while character just read is not a newline or invalid character
		while ((nextChar != '\n') && lastCharValid)
		{
			cout << nextChar; // Output Roman numeral character just read

			// Switch on the roman numeral character just read
			switch (nextChar)
			{

			case 'M':
				value = 1000;
				break;

			case 'D':
				value = 500;
				break;

			case 'C':
				value = 100;
				break;

			case 'L':
				value = 50;
				break;

			case 'X':
				value = 10;
				break;

			case 'V':
				value = 5;
				break;

			case 'I':
				value = 1;
				break;

			default:
				lastCharValid = false;

			}

			// If the character just processed was valid
			if (lastCharValid)
			{
				// We subtract previousValue * 2 if in the previous iteration we added
				// when we should have subtracted.
				if (previousValue < value)
				{	
					sum -= (2 * previousValue);
				}

				sum += value; //Add value just read

				previousValue = value; // value now becomes previous value for next iteration

				nextChar = cin.get(); // Input next char
				nextChar = toupper(nextChar); // Convert to uppercase if not already uppercase
			}
		}

		// If the last character processed was valid
		if (lastCharValid)
		{
			cout << " = " << sum << endl;
		}
		else
		{
			cout << " Error - last character was not valid!!! " << endl;

			// Skip past remaining characters to get to next Roman numeral number
			// Could have used instead:
			//    cin.ignore(INT_MAX, '\n'); // flush the input buffer

			do {
				nextChar = getchar();  // read next char and discard
			} while (nextChar != '\n');

		}
	}

	cout << "\nTHAT'S ALL FOLKS :)\n" << endl;
	system("pause");
}