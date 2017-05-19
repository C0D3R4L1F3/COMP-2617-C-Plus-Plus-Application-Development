// Filename: RHSCEmployeeMain.cpp
// Description: Calculate gross pay, net pay, pension and deductions 
//				for employees of Rogers Hostpital Supplies Company.
//
// Version: 1.0
// Created: 17/03/17 9:30AM
// Author: Ronnie Manimtim

#include <iostream>
#include <conio.h>  // Required for _getch() function
#include <fstream>  // Required for file input/output
#include <iomanip>
using namespace std;

// Global constants
#define TITLE_SEPERATOR "---------------------------------\n"
#define HEADER_SEPERATOR "--------------------------------------------------------------------"
#define SUMMARY_SEPERATOR "-------\n"
#define REGHOUR 40
#define MAXHOUR 54
#define MAXEXEM 20
#define MINPAY 25.00
#define MAXRATE 99.99
#define SINMIN  99999999
#define SINMAX  1000000000

// One way to specify a file name:
const char * IN_FILE = "EmployeePayInput.txt";

// A second way to specify a file name:
#define OUT_FILE "EmployeePayOutput.txt"

// Error messages for each type of invalid data
const char invalidDataErrMsg[] = "INVALID DATA ERROR: ";
const char invalidSinMsg[] = "Invalid social security #";
const char invalidHrsMsg[] = "Invalid hours wokred: ";
const char invalidExmMsg[] = "Invalid number of exemptions: ";
const char invalidPayMsg[] = "Invalid pay rate: ";
const char title[] = "Rogers Hospital Supplies Company\n";
const char summaryHeader[] = "\nSummary";

// Header titles for displaying employee record information
const char strSinHeader[] = "Social insurance no.";
const char strGrossHeader[] = "gross pay";
const char strNetHeader[] = "net pay";
const char strPensionHeader[] = "pension";
const char strDeductHeader[] = "deductions";

// Description for each summary category
const char strEmployeesTotal[] = "Number of employees processed: ";
const char strGrossPayTotal[] = "Total gross pay for all employees: ";
const char strNetPayTotal[] = "Total net pay for all employees: ";
const char strPensionTotal[] = "Total pension witheld for all employees: ";
const char strDeductionTotal[] = "Total deductions for all employees: ";

// Displays specified eror message
template<typename T>
void displayInvalidDataErrMsg(const char *, const char *, const long &, const T &);
void displayInvalidDataErrMsg(const char *, const char *, const long &);

bool validSin(const long &); // Validates Social insurance no.
bool validHours(const double &); // Validates hours worked
bool validPay(const double &); // Validates pay rate
bool validExempt(const int &); // Validates number of exemptions

double calculateGross(const double &, const double &); // Calculates gross
double calculateDeductions(const double &, const int &); // Calculates deductions
double calculatePension(const double &); // Calculates pension
double calculateNet(const double &, const double &, const double &); // Calculates net

// Function main begins program execution 
int main()
{
	cerr << fixed << setprecision(2) << showpoint;

	//Declare variables
	long socialInsuranceNum = 0; // Will store social security number of employee
	int numberOfExemptions = 0;  // Will store number of excemptions for employee
	int totalEmployees = 0;

	double payRate = 0.0; // Will store the pay rate for the employee
	double hoursWorked = 0.0; // Will store hours worked for the employee
	double grossPay = 0.0;
	double netPay = 0.0;
	double pension = 0.0;
	double deductions = 0.0;
	double totalGross = 0.0;
	double totalNet = 0.0;
	double totalWitheld = 0.0;
	double totalDeducted = 0.0;

	// Define ifstream object and open file
	ifstream ins;
	ins.open(IN_FILE);

	// Check that file opened without any issues
	if (ins.fail())
	{
		cerr << "ERROR--> Unable to open input file : " << IN_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // Causes execution to pause until a char is entered
		return -1; // Error return code
	} // End if

	// Define ofstream object and open file
	ofstream outs;
	outs.open(OUT_FILE);

	// Check that file opened without any issues
	if (outs.fail())
	{
		cerr << "ERROR--> Unable to open output file : " << OUT_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -2; //error return code
	} // End if

	// Read in first social security number
	ins >> socialInsuranceNum;

	outs << title << TITLE_SEPERATOR << '\n' << strSinHeader << setw(12) << strGrossHeader <<
		setw(12) << strNetHeader << setw(12) << strPensionHeader << setw(12) <<
		strDeductHeader << '\n' << HEADER_SEPERATOR << endl;

	// Process data until end of file is reached
	while (!ins.eof())
	{
		// Read in other data for the employee
		ins >> payRate >> numberOfExemptions >> hoursWorked;

		// Ensure that data is validated prior to writting it to the file
		if ((validSin(socialInsuranceNum) && validPay(payRate) && validExempt(numberOfExemptions) && validHours(hoursWorked)))
		{
			// Calculate data for record entry once validation concludes
			grossPay = calculateGross(hoursWorked, payRate);
			pension = calculatePension(grossPay);
			deductions = calculateDeductions(grossPay, numberOfExemptions);
			netPay = calculateNet(grossPay, pension, deductions);

			// Write data to file
			outs << socialInsuranceNum << "\t" << fixed << showpoint <<
				setprecision(2) << setw(16) << grossPay << setw(12) <<
				netPay << setw(12) << pension << setw(12) << deductions << '\n';

			// Keep track of data totals for Summary
			totalEmployees++;
			totalGross += grossPay;
			totalNet += netPay;
			totalWitheld += pension;
			totalDeducted += deductions;
		} // End if

		// Display error messages relevant to invalid data SIN
		if (!validSin(socialInsuranceNum))
		{
			displayInvalidDataErrMsg(invalidDataErrMsg, invalidSinMsg, socialInsuranceNum);
		} // End if

		// Pay rate
		if (!validPay(payRate))
		{
			displayInvalidDataErrMsg(invalidDataErrMsg, invalidPayMsg,
				socialInsuranceNum, payRate);
		} // End if

		// Number of exemptions
		if (!validExempt(numberOfExemptions))
		{
			displayInvalidDataErrMsg(invalidDataErrMsg, invalidExmMsg, socialInsuranceNum, numberOfExemptions);
		} // End if

		// Hours worked
		if (!validHours(hoursWorked))
		{
			displayInvalidDataErrMsg(invalidDataErrMsg, invalidHrsMsg, socialInsuranceNum, hoursWorked);
		} // End if

		// Read in next social security number
		ins >> socialInsuranceNum;
	} // End while

	// Close files
	ins.close();
	outs.close();

	// Open file to with append option to include summary
	outs.open(OUT_FILE, ios_base::app | ios_base::out);

	outs << "\n\n" << summaryHeader << '\n' << SUMMARY_SEPERATOR << fixed << showpoint << setprecision(2) <<
		'\n' << strEmployeesTotal << setw(27) << totalEmployees <<
		'\n' << strGrossPayTotal << setw(23) << totalGross <<
		'\n' << strNetPayTotal << setw(25) << totalNet <<
		'\n' << strPensionTotal << setw(17) << totalWitheld <<
		'\n' << strDeductionTotal << setw(22) << totalDeducted << endl;

	outs.close(); // Close file after appending summary

	cout << '\n' << endl;

	_getch(); // Causes execution to pause until char is entered
} // End main

// Validates social insurance number
bool validSin(const long &sin)
{
	return sin > SINMIN &sin < SINMAX;
} // End validSin

// Validates hours
bool validHours(const double &hours)
{
	return hours >= NULL &hours <= MAXHOUR;
} // End validHours

// Validates pay
bool validPay(const double &pay)
{
	return pay >= NULL &pay <= MAXRATE;
} // End validPay

// Validates excemptions
bool validExempt(const int &exempt)
{
	return exempt >= NULL &exempt < MAXEXEM;
} // End validExempt

// The overloaded version of this function is intended to display the invalid data. 
template<typename T>
void displayInvalidDataErrMsg(const char *errMsg, const char *errTypeMsg, const long &sin, const T &data)
{
	cerr << right << setw(10) << sin << "\t" << errMsg << "\t" << errTypeMsg << data << endl;
} // End displayInvalidDataErrMsg

// Displays an errror message due to an invalid SIN number
void displayInvalidDataErrMsg(const char *errMsg, const char *errTypeMsg, const long &sin)
{
	cerr << right << setw(10) << sin << "\t" << errMsg << "\t" << errTypeMsg << endl;
} // End displayInvalidDataErrMsg

// Calculate gross payment taking overtime into account
double calculateGross(const double &hours, const double &pay)
{
	double regular = 0.0;
	double extra = 0.0;
	double gross = 0.0;
	double otRate = 1.5;

	if (hours <= REGHOUR)
	{
		regular = hours;
	}
	else
	{
		regular = REGHOUR; extra = hours - REGHOUR;
	} // End if

	gross = ((regular * pay) + (extra * (pay * otRate)));

	return gross;
} // End calculateGross

// Calculate deductions and ensure that they do no exceed Gross pay
double calculateDeductions(const double &gross, const int &exempt)
{
	double pension = calculatePension(gross);
	double provincial = 0.35;
	double taxable = 0.0;
	double federalTax = 0.0;
	double provincialTax = 0.0;
	double deductions = 0.0;

	taxable = gross - (14.00 * exempt) - 11.00;
	federalTax = taxable * (0.14 + (0.00023 * taxable));
	provincialTax = federalTax * provincial;

	if (gross > MINPAY)
	{
		deductions = pension + federalTax + provincialTax;
	}
	else
	{
		deductions = pension;
	} // End if

	return deductions;
} // End calculateDeductions

// Calculate pension
double calculatePension(const double &gross)
{
	double pension = 0.0;
	double percent = 0.077;
	double rate = 16.50;
	pension = gross * percent;

	if (rate < pension)
	{
		pension = rate;
	} // End if

	return pension;
} // End calculatePension

// Calculate Net Payment 
double calculateNet(const double &gross, const double &pension, const double &deductions)
{
	double net = 0.0;

	if (gross == NULL)
	{
		net = gross;
	}
	else
	{
		net = gross - deductions;
	} // End if

	return net;
} // End calculateNet