// Created by James Peace

#include<iomanip>
#include<string>
#include<vector>
#include <cstdlib>
#include "project2.h"

using namespace std;

// Initialize variables.
double initialInvestmentAmount = 0.0;
double initialInvestment = 0.0;
double monthlyDepositAmount = 0.0;
double interestRateAmount = 0.0;
double interestRate = 0.0;
double annualInterest = 0.0;
double monthlyInterestAmount;
double accountBal;
int numberOfYears = 0;
int numYears = 0;
int yearIndex = 0;

Project2 display;
Project2 userInput;

// Constructors
void Project2::SetInitialInvestmentAmount(double initialInvestment) {
	initialInvestmentAmount = initialInvestment;
}
void Project2::SetMonthlyDeposit(double monthlyDeposit) {
	monthlyDepositAmount = monthlyDeposit;
}
void Project2::SetAnnualInterest(double interestRate) {
	annualInterest = interestRate;
}
void Project2::SetNumberOfYears(int numberOfYears) {
	yearNum = numberOfYears;
}

// Accessors
double Project2::GetInitialInvestmentAmount() {
	return initialInvestmentAmount;
}
double Project2::GetMonthlyDeposit() {
	return monthlyDepositAmount;
}
double Project2::GetInterestRate() {
	return annualInterest;
}
int Project2::GetNumberOfYears() {
	return yearNum;
}
bool Project2::UserInputandValidation() {

	char quitCmd = 'a';

	while (quitCmd != 'q') {
		cout << "" << setfill('*') << setw(42) << "" << endl;
		cout << "" << setfill('*') << setw(15) << "" << " Data Input " << "" << setfill('*') << setw(15) << "" << endl;
		cout << " Initial Investment Amount: " << endl;
		cout << " Monthly Deposit: " << endl;
		cout << " Annual Interest: " << endl;
		cout << " Number of years: " << endl << endl;

		// Accept my inputs
		cout << " Enter Initial Investment: ";
		cin >> initialInvestmentAmount; // Accepts user input
		
		if (initialInvestmentAmount >= 0.0) {
			userInput.SetInitialInvestmentAmount(initialInvestmentAmount); // Sets value into constructor
			cout << " Enter Monthly Deposit: ";
			cin >> monthlyDepositAmount; // Accepts user input
			if (monthlyDepositAmount >= 0.0) {
				userInput.SetMonthlyDeposit(monthlyDepositAmount); // Sets value into constructor
				cout << " Enter Annual Interest: ";
				cin >> annualInterest; // Accepts user input
				if (annualInterest >= 0.0) {
					userInput.SetAnnualInterest(annualInterest); // Sets value into constructor
					cout << " Enter Number of Years: ";
					cin >> yearNum; // Accepts user input
					if (yearNum >= 0) {
						userInput.SetNumberOfYears(yearNum);
						cout << "" << setfill('*') << setw(42) << "" << endl;
						cout << "" << setfill('*') << setw(15) << "" << " Data Input " << "" << setfill('*') << setw(15) << "" << endl;
						cout << setw(27) << " Initial Investment Amount:" << setfill(' ') << setw(3) << "$" << fixed << setprecision(2) << userInput.GetInitialInvestmentAmount() << endl;
						cout << " Monthly Deposit:" << setfill(' ') << setw(13) << "$" << userInput.GetMonthlyDeposit() << fixed << setprecision(2) << endl;
						cout << " Annual Interest:" << setfill(' ') << setw(17) << userInput.GetInterestRate() << fixed << setprecision(2) << "%" << endl;
						cout << " Number of years:" << setfill(' ') << setw(14) << userInput.GetNumberOfYears() << endl;
					}
					else {
						cout << " Invalid Entry: Please enter a number greater than 0. ";
						cin >> yearNum; // Accepts user input
					}
				}
				else {
					cout << " Invalid Entry: Please enter a number greater than 0. ";
					cin >> annualInterest; // Accepts user input
				}
			}
			else {
				cout << " Invalid Entry: Please enter a number greater than 0. ";
				cin >> annualInterest; // Accepts user input
			}
		}
		else {
			cout << " Invalid Entry: Please enter a number greater than 0. ";
			cin >> initialInvestmentAmount; // Accepts user input
		}
		cout << endl << " ";
		system("pause");

		return 0;
	}
}
// Primary methods
double Project2::CalculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
	// initialize local variables
	double yearEndBalance = 0.0;

	initialInvestment = userInput.GetInitialInvestmentAmount();
	interestRate = userInput.GetInterestRate();
	interestRate = interestRate / 100;
	// for loop to calculate balance based on annual interest
	for (int i = 0; i < yearNum; ++i) {
		yearEndBalance = initialInvestment * pow(1 +interestRate / 12, 12);
		interestEarnedThisYear = yearEndBalance - initialInvestment;
		yearIndex = i + 1;
		PrintDetails(yearIndex, yearEndBalance, interestRate); // Calls function for output layout
		cout << "  ";
		initialInvestment = yearEndBalance;
	}
	return yearEndBalance;
}

double Project2::BalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
	// initialize local variables
	double yearEndBalance = 0.0;
	double finalAmount = 0.0;

	initialInvestment = userInput.GetInitialInvestmentAmount();
	interestRate = userInput.GetInterestRate();
	monthlyDeposit = userInput.GetMonthlyDeposit();
	// for loop to calculate balance based on annual interest
	for (int i = 0; i < yearNum; ++i) {
		yearEndBalance = finalAmount;
		yearIndex = i + 1;
		PrintDetails(yearIndex, yearEndBalance, interestRate); // Calls function for output layout
		cout << "  ";
		initialInvestment = yearEndBalance;
	}

	return yearEndBalance;
}

// Primary functions
void Project2::CalcYearInterest(double initialAmount, double& interestAmount, double& finalAmount) {
	// Majority of this function was written by Eric Gregori of SNHU
	// Initialize local variables
	interestAmount = 0.0;
	// Altered local variables to fit universal variables used
	accountBal = initialInvestmentAmount;
	finalAmount = accountBal;
	// for loop to calculate yearly compounding interest
	// Written by Eric Gregori of SNHU
	for (int month = 0; month < 12; month++) {
		finalAmount += monthlyDepositAmount;
		monthlyInterestAmount = finalAmount * ((annualInterest / 100.0) / 12.0);
		finalAmount += monthlyInterestAmount;
		interestAmount += monthlyInterestAmount;
	}
	// Sets the output of function displayed in the chart located in PrintDetails()
	cout << finalAmount << right << setw(35) << fixed << setprecision(2) << " " << interestAmount << endl;

	return;
}

void Project2::DisplayNoMonthly() {
	// Sets the output for the header section of the chart for no monthly deposit section
	cout << "" << setfill(' ') << setw(7) << " " << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "" << setfill('=') << setw(70) << "" << endl;
	cout << "" << setfill(' ') << setw(2) << " " << "Year" << setw(11) << "" << "Year End Balance" << setw(11) << " " << "Year End Earned Interest" << endl;
	cout << "" << setfill('-') << setw(70) << "" << endl;
	cout << "" << setfill(' ') << setw(2) << " ";
	CalculateBalanceWithoutMonthlyDeposit(initialInvestmentAmount, interestRateAmount, numYears); // Calls method to initialize and output loops
	cout << endl;
	return;
}

void Project2::PrintDetails(int year, double yearEndBalance, double interestEarned) {
	// Initilaize local variables
	double accountBal = 0.0;
	double compoundInterestEarnedThisYear = 0.0;

	yearIndex = yearIndex;
	balance = yearEndBalance;
	accountBal = initialInvestmentAmount;
	// if loop to output two different charts based on monthly deposit yes or no
	if (balance = yearEndBalance) {
		cout << "" << setfill(' ') << right << setw(4) << yearIndex << setfill(' ') << setw(4) << right << setfill(' ') << setw(27) << fixed << setprecision(2) << balance << right << setw(35)
			<< fixed << setprecision(2) << " " << interestEarnedThisYear << endl;
	}
	else {
		cout << "" << setfill(' ') << right << setw(4) << yearIndex << setfill(' ') << setw(4) << right << setfill(' ') << setw(27) << fixed << setprecision(2);
		CalcYearInterest(initialInvestmentAmount, interestRateAmount, initialInvestmentAmount); // Calls method to initialize and output loops
	}
	return;

}

void Project2::DisplayWithMonthly() {
	// Sets the output for the header section of the chart for monthly deposit section
	cout << "" << setfill(' ') << setw(7) << " " << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "" << setfill('=') << setw(70) << "" << endl;
	cout << "" << setfill(' ') << setw(2) << " " << "Year" << setw(11) << "" << "Year End Balance" << setw(11) << " " << "Year End Earned Interest" << endl;
	cout << "" << setfill('-') << setw(71) << " " << endl;
	cout << "" << setfill(' ') << setw(2) << " ";
	BalanceWithMonthlyDeposit(initialInvestment, monthlyDepositAmount, interestRate, numberOfYears); // Calls method to initialize and output loops
	cout << endl;
	return;
}