#pragma once

// Filename:  Employee.h
// Description:  Exercise 3.11 - Definition of Employee class.
//
// Version:  1.0
// Created:  18/01/17 07:59PM
// Author:  Ronnie Manimtim

#include <string>

class Employee
{
public:
	Employee(std::string, std::string, int); // Constructor initializes Employee

	// Mutators
	void setFirstName(std::string); // Sets the Employee firstName
	void setLastName(std::string); // Sets the Employee lastName
	void setMonthlySalary(int); // Sets the Employee monthlySalary

	// Accessors
	std::string getFirstName() const; // Returns the firstName
	std::string getLastName() const; // Returns the lastName
	int getMonthlySalary() const; // Returns the monthlySalary

private:
	std::string firstName; // Data member that stores the Employee firstName
	std::string lastName; // Data member that stores the Employee lastName
	int monthlySalary; // Data member that stores the Employee monthlySalary
}; // end class Employee