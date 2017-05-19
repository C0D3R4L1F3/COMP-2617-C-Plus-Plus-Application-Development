// Filename:  Employee.cpp
// Description:  Exercise 3.11 - Member-function definitions for class Employee.
//
// Version:  1.0
// Created:  18/01/17 08:15PM
// Author:  Ronnie Manimtim

#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

const int NO_SALARY = 0;
const int INVALID_STRING_LENGTH = 1;

// Employee constructor initializes data members firstName, lastName, and monthlySalary
Employee::Employee(string newFirstName, string newLastName, int newMonthlySalary)
{
	setFirstName(newFirstName);
	setLastName(newLastName);
	setMonthlySalary(newMonthlySalary);
} // End Employee constructor

// Sets the Employee first name
void Employee::setFirstName(string newFirstName)
{
	// Invalid legnth for first name entered?
	if (newFirstName.length() <= INVALID_STRING_LENGTH)
	{
		// Initial first name unchanged
		if (firstName.length() > INVALID_STRING_LENGTH)
		{
			cerr << "\nERROR - invalid length string entered for first name in setFirstName(): " << newFirstName;
			cout << "\nThe first name was left unchanged: " << getFirstName() << endl;
		}
		else  // String entered used
		{
			firstName = newFirstName;

			cerr << "\nWarning - invalid length string entered for first name in ctor: " << newFirstName;
			cout << "\nThe string that was entered will be used for now." << endl;
		}
	}
	else
	{
		firstName = newFirstName;
	}
} // End function setFirstName

// Sets the Employee last name
void Employee::setLastName(string newLastName)
{
	// Invalid length for last name entered?
	if (newLastName.length() <= INVALID_STRING_LENGTH)
	{
		// Initial last name unchanged
		if (lastName.length() > INVALID_STRING_LENGTH)
		{
			cerr << "\nERROR - invalid length string entered for last name in setLastName(): " << newLastName;
			cout << "\nThe last name was left unchanged: " << getLastName() << endl;
		}
		else // String entered used
		{
			lastName = newLastName;

			cerr << "\nWarning - invalid length string entered for last name in ctor: " << newLastName;
			cout << "\nThe string that was entered will be used for now." << endl;
		}
	}
	else
	{
		lastName = newLastName;
	}
} // End function setLastName

// Sets the Employee monthly salary
void Employee::setMonthlySalary(int newMonthlySalary)
{
	// Invalid salary entered? 
	if (newMonthlySalary < NO_SALARY)
	{
		// Initial salary unchanged
		if (monthlySalary > NO_SALARY)
		{
			cerr << "\nERROR - Invalid salary amount specified : $" << newMonthlySalary;
			cout << "\nSalary was left unchanged at: $" << getMonthlySalary() << endl;
		}
		else // Salary set to NO_SALARY
		{
			monthlySalary = NO_SALARY;

			cerr << "\nInvalid salary amount specified : $" << newMonthlySalary;
			cout << "\nSalary set to $" << getMonthlySalary() << " instead." << endl;
		}
	}
	else
	{
		monthlySalary = newMonthlySalary;
	}
} // End function setMonthlySalary

// Returns the first name
string Employee::getFirstName() const
{
	return firstName;
} // End function getFirstName

// Returns the last name
string Employee::getLastName() const
{
	return lastName;
} // End function getLastName

// Returns the monthly salary
int Employee::getMonthlySalary() const
{
	return monthlySalary;
} // End function getMonthlySalary