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

int clash(Character a, Character b) {
	int l1 = a.speed_number;
	int l2 = b.speed_number;
	int l = min(l1, l2);
	for (int i = 0; i < l; i++) {
		int c1 = a.dices[i].size();
		int c2 = b.dices[i].size();
		int c = min(c1, c2);
		for (int j = 0; j < c; j++) {
			int r1 = RandomInRange(a.dices[i][j].m, a.dices[i][j].M);
			int r2 = RandomInRange(b.dices[i][j].m, b.dices[i][j].M);
			if (r1 > r2) {
				b.hp_damage(r1);
				b.stagger_damage(r1);
			}
			else if (r1 < r2) {
				a.hp_damage(r2);
				a.stagger_damage(r2);
			}
		}
		if (c1 > c2) {
			for (int j = c; j < c1; j++) {
				int r1 = RandomInRange(a.dices[i][j].m, a.dices[i][j].M);
				b.hp_damage(r1);
				b.stagger_damage(r1);
			}
		}
		else if (c1 < c2) {
			for (int j = c; j < c2; j++) {
				int r2 = RandomInRange(b.dices[i][j].m, b.dices[i][j].M);
				a.hp_damage(r2);
				a.stagger_damage(r2);
			}
		}
	}
}