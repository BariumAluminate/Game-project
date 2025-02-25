#include <iostream>
#include "Card.h"
using namespace std;

class Character
{
public:
	int hp, sp, stagger, speed_dice_amount;
	Character() {
		hp = 30;
		sp = 0;
		stagger = 30;
		speed_dice_amount = 1;
	}
	void hp_damage(int damage) {
		hp -= damage;
	}
	void stagger_damage(int damage) {
		stagger -= damage;
	}
};