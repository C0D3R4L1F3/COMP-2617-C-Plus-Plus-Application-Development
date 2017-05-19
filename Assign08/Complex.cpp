// Filename:  Complex.cpp
// Description:  Assignment 08 EX9.5 Member-function definitions for class Complex.
// Version:  1.0
// Author:  Ronnie Manimtim
// Date: 03/30/17 9:16PM

#include "Complex.h"
#include <iomanip>
#include <iostream>
using namespace std;

//Default Ctor takes 2 default values
Complex::Complex(const double &newRealPart, const double &newImaginaryPart)
	:realPart(newRealPart), imaginaryPart(newImaginaryPart)
{
} // End Ctor

//Adds complex numbers
const Complex &Complex::plusEq(const Complex &op)
{
	realPart += op.getRealPart();
	imaginaryPart += op.getImginaryPart();

	return (*this);
} // End plusEq

//Subtracts complex numbers
const Complex &Complex::minusEq(const Complex &op)
{
	realPart -= op.getRealPart();
	imaginaryPart -= op.getImginaryPart();

	return (*this);
} // End minusEq

//Display results
void Complex::display() const
{
	cout << fixed << setprecision(4);
	cout << "( " << getRealPart() << " , " << getImginaryPart() << " )";
} // End display

// Sets real part
void Complex::setRealPart(const double &newRealPart)
{
	this->realPart = newRealPart;
} // End setRealPart

// Sets imaginary part
void Complex::setImginaryPart(const double &newImginaryPart)
{
	this->imaginaryPart = newImginaryPart;
} // End setImginaryPart

// Returns real part
double Complex::getRealPart() const
{
	return realPart;
} // End getRealPart

// Returns imaginary part
double Complex::getImginaryPart() const
{
	return imaginaryPart;
} // End getImginaryPart