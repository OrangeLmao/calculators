//============================================================================
// File Name : FToCCalulator > main.cpp
// Author : Pranav Saran
// Copyright : BigCopyrightCompany.co
// Description : This program will convert Fahrenheit to Celsius
// Revision History:
// Date                      Version         Change ID               Author                     Comment
// 04-16-23					 1.0             123                     Pranav Saran               Initial creation
//============================================================================

#include <cmath>;
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	bool toggle = true;
	string response = "";

	while (toggle) {
		double c;
		double f;
		cout << "Enter a Fahrenheit temperature:" << endl;
		cin >> f;

		c = (f - 32) * 5 / 9;

		cout << "The Celsius result is: " << c << endl;
		cout << "Do you want to run the program again? (y/n)" << endl;
		cin >> response;
		if (response == "n") {
			toggle = false;
		}

	}

	return 0;
}