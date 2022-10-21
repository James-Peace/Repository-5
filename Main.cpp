#include<iostream>
#include<iomanip>
#include<string>
#include "project2.h"

using namespace std;

int main(void)  {
	Project2 display;

	display.UserInputandValidation(); // Displays main menu options and output.

	cout << endl << endl;
	display.DisplayNoMonthly(); // Displays chart for calculations without monthly deposits
	display.DisplayWithMonthly(); // displays chart for calculations with monthly deposits

	return 0;

}