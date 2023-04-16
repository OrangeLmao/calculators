//============================================================================
// File Name : MorgageCalculation > main.cpp
// Author : Pranav Saran
// Copyright : BigCopyrightCompany.co
// Description : This program will help calculate monthly mortgage payments and property tax.
// Revision History:
// Date                      Version         Change ID               Author                     Comment
// 04-16-23					 1.1             156                     Pranav Saran               Initial creation
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
const double annualTaxRate = 1.5;

void  Delay(int  milliseconds, std::string delay_msg = "", char  delay_symbol = '.');

int main() {
	string input;
	string address;
	string zipcode, offerPrice, downPayment, financeYears, aInterestRate;
	//input variables
	int zipcodeV, offerPriceV; 
	double downPaymentV, aIntrestRateV, financeNumberV;
	//output variables
	double totalDownPayment,monthlyInterestRate, monthlyMorgage, monthlyPropTax, totalMonPayment, totalPayment;
	int loanAmount;
	int loanMaturityDate;

	
	cout << " Enter property zip code, offer price, down payment, number of years financing, and annual interest rate: (make sure there is a space between inputs)  " << endl;
	getline(cin,input);
	stringstream ss(input);
	ss >> zipcode >> offerPrice >> downPayment >> financeYears >> aInterestRate;
	cout << "Enter property address: " << endl;
	getline(cin, address);

	zipcodeV = stoi(zipcode);
	offerPriceV = stoi(offerPrice);
	financeNumberV = stoi(financeYears);

	downPaymentV = stod(downPayment);
	aIntrestRateV = stod(aInterestRate);
	
	//Calculations Begin here:
	totalDownPayment = offerPriceV * downPaymentV / 100;
	loanAmount = offerPriceV - totalDownPayment;
	loanMaturityDate = financeNumberV + 2022;
	financeNumberV /= 1.0;
	monthlyInterestRate = aIntrestRateV / 1200;
	monthlyMorgage = loanAmount * monthlyInterestRate / (1 - 1 / pow(1 + monthlyInterestRate, financeNumberV * 12));
	monthlyPropTax = offerPriceV * annualTaxRate / 100 / 12;
	totalMonPayment = monthlyMorgage + monthlyPropTax;
	totalPayment = (monthlyMorgage * 12 * financeNumberV);

	

	Delay(1500, "Mortgage calculator is processing your data. Please wait ...");
	cout << endl;
	cout << "                     **************************************\n"
		<< "                      MORTGAGE CALCULATOR RESULTS\n"
		<< "                     **************************************\n"
		<< "Property Adress: " << address << "\n"
		<< "Property Offer Price: " << offerPriceV << "\n"
		<< "Total Down Payment: " << totalDownPayment  << "\n"
		<< "Loan Amount: " << loanAmount  << "\n"
		<< "Loan Maturity Date: 12/31/" << loanMaturityDate << "\n"
		<< "Monthly Moragage Payment: " << monthlyMorgage  << "\n"
		<< "Total Monthly Payment(with property tax): " << totalMonPayment << "\n"
		<< "Total Payment (exlcluding tax): " << totalPayment << "\n";


	return 0;
}
void Delay(int  milliseconds, std::string delay_message, char  delay_symbol) {
	const int kCyclesPerMilliSecond = 600000;

	std::cout << delay_message << std::flush;
	for (int millisecond = 0; millisecond < milliseconds; ++millisecond) {
		for (int cycle = 0; cycle <= kCyclesPerMilliSecond; ++cycle) {
			if (millisecond % 1000 == 0 && cycle == kCyclesPerMilliSecond) {    // print a symbol every second
				std::cout << delay_symbol << std::flush;
			}
		}
	}
}