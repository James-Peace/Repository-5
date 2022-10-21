#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#ifndef PROJECT_2_H
#define PROJECT_2_H

class Project2 {
private:
	// Primary private variables
	double initialInvestmentAmount;
	double annualInterest;
	double balance;
	double interestEarnedThisYear;
	int yearNum;
	// Private class methods
	double CalculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);
	double BalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
	void PrintDetails(int year, double yearEndBalance, double interestEarned);
	void CalcYearInterest(double initialAmount, double &interestAmount, double &finalAmount);
	
public:
	// Primary class functions
	bool UserInputandValidation(void);
	void DisplayNoMonthly(void);
	void DisplayWithMonthly(void);
	void SetInitialInvestmentAmount(double);
	// Setters
	void SetMonthlyDeposit(double);
	void SetAnnualInterest(double);
	void SetNumberOfYears(int);
	// Getters
	double GetInitialInvestmentAmount();
	double GetMonthlyDeposit();
	double GetInterestRate();

	int GetNumberOfYears();

};

#endif

