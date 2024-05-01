//============================================================================
// File Name : CarDealershipWorking > main.cpp
// Author : Pranav Saran
// Copyright : BigCopyrightCompany.co
// Description : program creates a smart car inquiry system where clients can view and search for certain cars
// Revision History:
// Date                      Version         Change ID               Author                     Comment
// 05-28-23					 1.0             123                     Pranav Saran               Initial creation
//============================================================================

#include <cmath>;
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void Delay(int  milliseconds, std::string delay_msg = "", char  delay_symbol = '.');
void LoadVehicleInventory(string make_model_list[], int year_list[], double price_list[], const int kVehicleCount);
void Menu();
int GetUserChoice();
void ShowVehicleInventory(string make_model_list[], int year_list[], double price_list[]);
bool Quit();
void SearchByMakeModel(string make_model_list[], int year_list[], double price_list[]);
void Run(string make_model_list[], int year_list[], double price_list[]);



int main() 
{
	const int k_array_size = 16;
	string make_model_list[k_array_size];
	int year_list[k_array_size];
	double price_list[k_array_size];

	LoadVehicleInventory(make_model_list, year_list, price_list, k_array_size);
	Run(make_model_list, year_list, price_list);
	
	return 0;
}

void Run(string make_model_list[], int year_list[], double price_list[])
{
	bool toggle = true;
	int choice = 0;
	do
	{
		Menu();
		choice = GetUserChoice();
		switch (choice)
		{
			case 1:
				ShowVehicleInventory(make_model_list, year_list, price_list);
				break;
			case 2:
				SearchByMakeModel(make_model_list, year_list, price_list);
				break;
			case 3:
				toggle = Quit();
				break;
			default:
				cout << "Invalid selection please try again" << endl;
		}
	} while (toggle);
}
void ShowVehicleInventory(string make_model_list[], int year_list[], double price_list[])
{
	
	for (int i = 0; i < 16; i++)
	{
		cout << make_model_list[i] << "\t" << year_list[i] << "\t" << price_list[i] << endl;
	}
}
int GetUserChoice()
{
	cout << "Enter an option: \n";
	int option = 0;
	cin >> option;
	return option;
}
void Menu()
{
	cout << "\t SMART CAR INQUIRY" << endl;
	cout << "1. View Vehicle Inventory" << endl;
	cout << "2. Search by Make and Model" << endl;
	cout << "3. Quit" << endl;
}
void LoadVehicleInventory(string make_model_list[], int year_list[], double price_list[], const int kVehicleCount) 
{
	string make_model = "";
	int year = 0;
	double price = 0.0;
	int rand_make_model = 0;
	double kMaxPrice = 0.00;
	double kMinPrice = 0.00;

	srand(static_cast <unsigned int> (time(0))); // generate a seed for the random generator
	cout << "Welcome to Best Dearlership\n";
	//invoke delay
	Delay(10, "Loading vehicles from database. Please wait ...\n", '.');
	for (int i = 0; i < kVehicleCount; i++) 
	{
		rand_make_model = rand() % 4;   // generate either 0, 1, 2 or 3
		switch (rand_make_model)
		{
			case 0:
				kMaxPrice = 30000.00;
				kMinPrice = 9000.00;
				price = kMinPrice + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (kMaxPrice - kMinPrice)));
				year = 2010 + (rand() % 7) + 1;
				make_model_list[i] = "Ford Taurus";
				year_list[i] = year;
				price_list[i] = price;
				break;
			case 1:
				kMaxPrice = 35000.00;
				kMinPrice = 12000.00;
				price = kMinPrice + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (kMaxPrice - kMinPrice)));
				year = 2010 + (rand() % 7) + 1;
				make_model_list[i] = "Toyota Camry";
				year_list[i] = year;
				price_list[i] = price;
				break;
			case 2:
				kMaxPrice = 63500.00;
				kMinPrice = 39500.00;
				price = kMinPrice + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (kMaxPrice - kMinPrice)));
				year = 2010 + (rand() % 7) + 1;
				make_model_list[i] = "BMW 335i";
				year_list[i] = year;
				price_list[i] = price;
				break;
			case 3:
				kMaxPrice = 199999.00;
				kMinPrice = 80000.00;
				price = kMinPrice + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (kMaxPrice - kMinPrice)));
				year = 2010 + (rand() % 7) + 1;
				make_model_list[i] = "R-R Phantom";
				year_list[i] = year;
				price_list[i] = price;
				break;
		
		}


	}

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
bool Quit()
{
	cout << "goodbye \n";
	return false;
}
void SearchByMakeModel(string make_model_list[], int year_list[], double price_list[])
{
	string response;
	cout << "Enter make or model \n";
	cin.ignore();
	getline(cin, response);

	if (response == "Ford Taurus")
	{
		for (int i = 0; i < 16; i++)
		{
			if (make_model_list[i] == "Ford Taurus" )
			{
				cout << make_model_list[i] << "\t" << year_list[i] << "\t" << price_list[i] << endl;
			}
		}
	}
	else if (response == "Toyota Camry")
	{
		for (int i = 0; i < 16; i++)
		{
			if (make_model_list[i] == "Toyota Camry")
			{
				cout << make_model_list[i] << "\t" << year_list[i] << "\t" << price_list[i] << endl;
			}
		}
	}
	else if (response == "BMW 335i")
	{
		for (int i = 0; i < 16; i++)
		{
			if (make_model_list[i]== "BMW 335i")
			{
				cout << make_model_list[i] << "\t" << year_list[i] << "\t" << price_list[i] << endl;
			}
		}
	}
	else if (response == "R-R Phantom")
	{
		for (int i = 0; i < 16; i++)
		{
			if (make_model_list[i]=="R-R Phantom")
			{
				cout << make_model_list[i] << "\t" << year_list[i] << "\t" << price_list[i] << endl;
			}
		}
	}
	else
	{
		cout << "invalid car\n";
	}

}

