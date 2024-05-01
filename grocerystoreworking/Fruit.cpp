#include "Fruit.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const string Fruit::DEFAULT_FRUIT_NAME = "TBD";
const double Fruit::DEFAULT_PRICE_PER_LBS = 0.0;
const double Fruit::DEFAULT_WEIGHT = 0.0;

//default constructor
Fruit::Fruit():
	fruit_name(Fruit::DEFAULT_FRUIT_NAME),
	weight(Fruit::DEFAULT_WEIGHT),
	price_per_lbs(Fruit::DEFAULT_PRICE_PER_LBS){}
//custom constructor
Fruit::Fruit(string fruit_name, double wieght, double price_per_lbs)
{
	this->fruit_name = fruit_name;
	this->weight = wieght;
	this->price_per_lbs = price_per_lbs;
}
//Deconstructor
Fruit::~Fruit() {
	cout << "Fruit " << fruit_name << "wieght = " << weight << "lbs rotten\n";
}

string Fruit:: get_fruit_name()
{
	return fruit_name;
}
double Fruit::get_wieght()
{
	return weight;
}
double Fruit:: get_price_per_lbs()
{
	return price_per_lbs;
}
void Fruit:: set_fruit_name(string fruit_name)
{
	this->fruit_name = fruit_name;
}
void Fruit:: set_wieght(double wieght)
{
	this->weight = wieght;
}
void Fruit:: set_price_per_lbs(double price_per_lbs)
{
	this->price_per_lbs = price_per_lbs;
}

//custom methods
void Fruit:: display()
{
	cout << fruit_name << " has a weight of " <<setprecision(2)<<weight<< " and costs " <<setprecision(2)<<price_per_lbs << " per lb\n";
}
double Fruit::order(double ordered_weight)
{
	if (ordered_weight > weight)
	{
		return -1;
	}
	else 
	{
		weight = weight - ordered_weight;
		return ordered_weight * price_per_lbs;
	}
}

