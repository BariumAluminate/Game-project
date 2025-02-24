#include <iostream>
#include "Header.h"
#include "Card.h"

using namespace std;

int main() {

	srand(time(0));

	Dice a, b;
	a.Dicetype = "Slash";
	a.m = 1;
	a.M = 6;
	b.Dicetype = "Slash";
	b.m = 1;
	b.M = 6;
	int clash_power1 = RandomInRange(a.m, a.M);
	int clash_power2 = RandomInRange(b.m, b.M);
	cout << "Clash power of the player 1 is " << clash_power1 << endl;
	cout << "Clash power of the player 2 is " << clash_power2 << endl;
	if ( clash_power1 > clash_power2 ) {
		cout << "Player 1 wins" << endl;
	}
	else if ( clash_power1 < clash_power2 ){
		cout << "Player 2 wins" << endl;
	}
	else { 
		cout << "Draw"<<endl;
	}
}