#include "Fruit.h"
#include "OnlineSuperMarket.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const double OnlineSuperMarket::sales_tax_rate = 0.09375;
const string OnlineSuperMarket::DEFAULT_STORE_NAME = "TBD";
const string OnlineSuperMarket::DEFAULT_WEB_ADDRESS = "https://www.unknown_store.com";

OnlineSuperMarket::OnlineSuperMarket() :  //default constructor 
	store_name(OnlineSuperMarket::DEFAULT_STORE_NAME),
	web_address(OnlineSuperMarket::DEFAULT_WEB_ADDRESS) {}
OnlineSuperMarket::OnlineSuperMarket(string web_address, string store_name) //custom constructor
{
	this->store_name = store_name;
	this->web_address = web_address;
}
OnlineSuperMarket::~OnlineSuperMarket() { //destructor
	cout << "Online super market " << store_name << "at " << web_address << " is closed" << endl;
}
//getters
string OnlineSuperMarket::get_store_name()
{
	return store_name;
}
string OnlineSuperMarket::get_web_address()
{
	return web_address;
}
//helpermethods
int OnlineSuperMarket::Find(string request_fruit)
{
    int low = 0;
    int high = array_size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        string fruit_name = list_of_fruit[mid].get_fruit_name();

        if (fruit_name == request_fruit) {
            return mid; // Found the fruit at index mid
        }
        else if (fruit_name < request_fruit) {
            low = mid + 1; // Search in the right half
        }
        else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Fruit not found
}
void OnlineSuperMarket::Quit()
{
    cout << "Thanks for your visit.Please come again." << endl;
}
//useful methods
void OnlineSuperMarket::Init()
{
    string names[array_size] = { "Orange", "Apple", "Bannana", "Dragonfruit", "Mango", "Peach", "Blackberry", "Hamimelon" };
    double weights[array_size] = { 5.3, 6.7, 4.16, 12.0, 6.0, 5.3, 1.2, 15.0 };
    double prices[array_size] = { 1.20, 1.20, 0.90, 5.50, 3.50, 2.50, 0.90, 1.00 };
    
    for (int i = 0; i < array_size; i++)
    {
        Fruit temp(names[i], weights[i], prices[i]);
        list_of_fruit[i] = temp;
        
    }
}
void OnlineSuperMarket::show_fruits()
{
    for (int i = 0; i < array_size; i++)
    {
        list_of_fruit[i].display();
    }
}
void OnlineSuperMarket::sort()
{
    bool swapped = false;
    for (int i = 0; i < array_size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < array_size - i - 1; ++j) {
            if (list_of_fruit[j].get_fruit_name() > list_of_fruit[j + 1].get_fruit_name()) {
                swap(list_of_fruit[j], list_of_fruit[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // If no swaps occurred in a pass, the array is already sorted
        }
    }
}
void OnlineSuperMarket::Run()
{
    bool is_shopping = true;
    string choice = "";
    string request_fruit = "";
    double request_amount = 0.0;
    double total_cost = 0.0;
    double temp_cost = 0.0;
    double ordered_amount = 0.0;
    cout << "Welcome to " << store_name << " at" << web_address << endl;
    while (is_shopping) 
    {
        cout << "(O)rder fruits or (Q)uit" << endl;
        cin >> choice;
        if (choice == "q" || choice == "Q")
        {
            show_fruits();
            Quit();
            is_shopping = false;
        }
        else
        {
            cout << "What fruit are you looking for?" << endl;
            cin >> request_fruit;
            int find = Find(request_fruit);
            if (find == -1)
            {
                cout << "Fruit not found." << endl;
                break;
            }
            else
            {
                cout << "Enter the weight of how much you want to order: " << endl;
                cin >> request_amount;
                ordered_amount = list_of_fruit[find].order(request_amount);
                if (ordered_amount == -1)
                {
                    cout << "Fruit can not be ordered due to a lack of inventory" << endl;
                    break;
                }
                else
                {
                    temp_cost = ordered_amount * sales_tax_rate;
                    total_cost = total_cost + temp_cost;
                    cout << "Your total order cost is " << total_cost << endl;
                }
            }
        }
    }

    


}



