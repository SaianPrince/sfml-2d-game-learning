#include <iostream>
#include <string>
#include "App.h"
using namespace std;


int main()
{
	Application App;
	App.create(1000, 1000);
	App.start(60);
}
