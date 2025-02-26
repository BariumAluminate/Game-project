#include <iostream>
#include "Card.h"
using namespace std;

class Character
{
public:
	int hp, level, sp, stagger;
	int vmax, vmin;
	int speed_number;
	vector <vector <Dice>> dices;
	Character() {
		hp = 30;
		level = 1;
		sp = 0;
		stagger = 30;
		vmax = 6;
		vmin = 1;
		speed_number = 1;
	}
	void print() const {
		cout << "HP: " << hp << endl;
		cout << "Level: " << level << endl;
		cout << "SP: " << sp << endl;
		cout << "Stagger: " << stagger << endl;
		cout << "Speed number: " << speed_number << endl;
	}
	void dices_import(vector <Dice> a) {
		dices.push_back(a);
	}
	void hp_damage(int a) {
		hp -= a;
		if (stagger == 0) {
			hp -= a;
		}
	}
	void stagger_damage(int a) {
		stagger -= a;
	}
};