// Filename:  GCD.h
// Description:  Asssignment 04 Template function
//				 that calculates the gcd of 2 denominators.
//
// Version:  1.0
// Created:  02/15/17 10:10PM
// Author:  Ronnie Manimtim

const int MIN_VALUE = 1;
const int START_VALUE = 0;

// gcd finds greatest common divisor of firstValue and secondValue
template<typename T>
T gcd(T firstValue, T secondValue)
{
	T gcd = MIN_VALUE; // Current greatest common divisor, 1 is minimum

	if (firstValue < START_VALUE)
	{
		firstValue = -firstValue;
	} // End if 

	if (secondValue < START_VALUE)
	{
		secondValue = -secondValue;
	} // End if 

	// Loop from 2 to smaller of firstValue and secondValue
	for (int current = MIN_VALUE; current <= firstValue && current <= secondValue; current++)
	{
		// Current divides both firstValue and secondValue
		if (firstValue % current == START_VALUE && secondValue % current == START_VALUE)
		{
			gcd = current; // Update greatest common divisor
		} // End if
	} // End for

	return gcd; // Return greatest common divisor found
} // End function gcd