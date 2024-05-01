#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Fruit.h"
#include "OnlineSuperMarket.h"

using namespace std;

int main()
{
	OnlineSuperMarket * market = nullptr;
	market = new OnlineSuperMarket(" BestWWMarket", "www.bestwwmarket.net");

	market->show_fruits();
	market->Init();
	market->show_fruits();
	market->sort();
	market->show_fruits();
	market->Run();

	

	return 0;
}