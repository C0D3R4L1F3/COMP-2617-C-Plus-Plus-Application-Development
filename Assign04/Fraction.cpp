// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  Ronnie Manimtim
// Date: 02/16/17 3:10PM

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

// Default ctor
Fraction::Fraction(void)
{
	numerator = START_VALUE;
	denominator = MIN_VALUE;
} // End constructor

// Second ctor, which requires at least one long long argument
Fraction::Fraction(long long num, long long denom)
	: numerator(num), denominator(denom)
{
	simplify(); // Makes sure that denominator is positive and
				// invokes gcd() function to reduce fraction
} // End constructor 

// Adds op to the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::plusEq(const Fraction & op)
{
	numerator *= op.denominator;
	numerator += op.numerator * denominator;
	denominator *= op.denominator;

	simplify(); // Makes sure that denominator is positive and
				// invokes gcd() function to reduce fraction

	return (*this); // Returns the object which invoked the method
} // End plusEq

// Subtracts op from the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::minusEq(const Fraction & op)
{
	numerator *= op.denominator;
	numerator -= op.numerator * denominator;
	denominator *= op.denominator;

	simplify();	// Makes sure that denominator is positive and
				// invokes gcd() function to reduce fraction

	return (*this); // Returns the object which invoked the method
} // End minusEq

// Multiples op from the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::timesEq(const Fraction & op)
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify(); // Makes sure that denominator is positive and
				// invokes gcd() function to reduce fraction

	return (*this); // Returns the object which invoked the method
} // End timesEq

// Divides op from the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::divideEq(const Fraction & op)
{
	numerator *= op.denominator;
	denominator *= op.numerator;

	simplify(); // Makes sure that denominator is positive and
				// invokes gcd() function to reduce fraction

	return (*this); // Returns the object which invoked the method
} // End divideEq

// Returns the negation of the Fraction object invoked with the method 
// but must NOT modify the actual Fraction object invoked with the method.
Fraction Fraction::negate(void) const
{
	// Creates a new Fraction object 
	Fraction fract = Fraction(-numerator, denominator);

	return fract; // Returns the temp object to the calling function
} // End negate

// Returns numerator
long long Fraction::getNum(void) const
{
	return numerator;
} // End getNum

// Returns denominator
long long Fraction::getDenom(void) const
{
	return denominator;
} // End getDenom

// Outputs to standard output stream the Fraction object
// in the format: numerator/denominator
void Fraction::display(void) const
{
	cout << numerator << "/" << denominator;
} // End display

// Reduces the Fraction objects as much as possible.
// It also ensures that the denominator is positive.
void Fraction::simplify(void)
{
	// Call the gcd template function and find the lowest common denom
	long long divisor = gcd(numerator, denominator);
	numerator /= divisor;
	denominator /= divisor;

	if (denominator < START_VALUE)
	{
		denominator = -denominator;
		numerator = -numerator;
	} // End if
} // End simplify