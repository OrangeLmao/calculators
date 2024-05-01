#pragma once
#include <string>

using namespace std;

class Fruit
{
	private:
		string fruit_name;
		double weight;
		double price_per_lbs;
	public:
		//default values
		static const string DEFAULT_FRUIT_NAME;
		static const double DEFAULT_WEIGHT;
		static const double DEFAULT_PRICE_PER_LBS;
		Fruit();
		Fruit(string fruit_name, double wieght, double price_per_lbs);
		~Fruit();
		string get_fruit_name();
		double get_wieght();
		double get_price_per_lbs();
		void set_fruit_name(string fruit_name);
		void set_wieght(double wieght);
		void set_price_per_lbs(double price_per_lbs);
		void display();
		double order(double ordered_weight);

};

