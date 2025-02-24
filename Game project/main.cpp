#include <iostream>
#include "Header.h"
#include "Card.h"

using namespace std;

int main() {
	Dice a, b;
	a.Dicetype = "Red";
	a.m = 1;
	a.M = 6;
	b.Dicetype = "Blue";
	b.m = 1;
	b.M = 6;
	if (clash(a,b)) {
		cout << "Red wins" << endl;
	}
	else {
		cout << "Blue wins" << endl;
	}
}