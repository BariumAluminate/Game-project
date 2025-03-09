#include "Card.h"
#include <vector>
using namespace std;

vector <card> deck;

card weakslash(0, 1);

card tripleslash(3, 3);

card fencing(1, 2);

void card_def() {
	

	dice a(0, 1, 6);

	for (int i = 0; i < 3; i++) {
		tripleslash.dice_import(a);
	}

	weakslash.dice_import(a);
	
	dice b(1, 2, 5);

	
	fencing.dice_import(b);
	fencing.dice_import(b);
}