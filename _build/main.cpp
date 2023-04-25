#include <iostream>
#include "Presenter.h"

using namespace std;

int main()
{   
	Presenter* p = new Presenter();
	p->startGame();

	delete p;
}