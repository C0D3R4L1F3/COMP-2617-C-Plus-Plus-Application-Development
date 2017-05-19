// Filename:  Complex.h
// Description:  Asssignment 08 EX9.5 Definition for Complex class
//				 Program that adds, subtracts and displays complex numbers.
// Version:  1.0
// Author:  Ronnie Manimtim
// Date: 03/30/17 9:16PM

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:

	Complex(const double & = 1.0, const double & = 0.0); //Default Ctor takes 2 default values

	const Complex &plusEq(const Complex &); //Add complex numbers

	const Complex &minusEq(const Complex &); //Subtract complex numbers

	void display() const; //Display results 

	// Mutators
	void setRealPart(const double &); // Sets real part
	void setImginaryPart(const double &); // Sets imaginary part

	// Accessors
	double getRealPart() const; // Returns real part
	double getImginaryPart() const; // Returns imaginary part

private:

	double realPart; // Represents real part
	double imaginaryPart; // Represent imaginary part
};
#endif