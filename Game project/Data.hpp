#include "Card.h"
#include <vector>
using namespace std;

card weakslash(0, 1);

card tripleslash(3, 3);

void card_def() {
	dice a(0, 1, 1, 6);

	for (int i = 0; i < 3; i++) {
		tripleslash.dice_import(a);
	}

	weakslash.dice_import(a);

}