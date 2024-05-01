#pragma once
#include "Fruit.h"
class OnlineSuperMarket
{
	
	public:
		static const int array_size = 8;
		static const double sales_tax_rate;
		static const string DEFAULT_STORE_NAME;
		static const string DEFAULT_WEB_ADDRESS;
		OnlineSuperMarket();
		OnlineSuperMarket(string store_name, string web_address);
		~OnlineSuperMarket();
		int Find(string request_fruit);
		void Quit();
		string get_store_name();
		string get_web_address();
		void Init();
		void sort();
		void Run();
		void show_fruits();

	private:
		Fruit list_of_fruit[array_size];
		string store_name;
		string web_address;
 
};

