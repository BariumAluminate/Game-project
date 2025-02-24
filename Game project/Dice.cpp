#include "Card.h"
using namespace std;

bool clash(Dice a, Dice b) {
	return a.clash_power() > b.clash_power();
}