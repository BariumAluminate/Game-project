#include <iostream>
#include <vector>
#include <ctime>
#include "Header.h"
#include "Card.h"
#include "Player.h"

using namespace std;

void clash(Character& a, Character& b) {
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
			cout << r1 << " " << r2 << endl;
			if (r1 > r2) {
				b.hp_damage(r1);
				b.stagger_damage(r1);
				cout << "Character b hp deplete: " << r1 << endl;
			}
			else if (r1 < r2) {
				a.hp_damage(r2);
				a.stagger_damage(r2);
				cout << "Character a hp deplete: " << r2 << endl;
			}
			else {
				cout << "No damage" << endl;
			}
		}
		if (c1 > c2) {
			for (int j = c; j < c1; j++) {
				int r1 = RandomInRange(a.dices[i][j].m, a.dices[i][j].M);
				b.hp_damage(r1);
				b.stagger_damage(r1);
				cout << "Character b hp deplete: " << r1 << endl;
			}
		}
		else if (c1 < c2) {
			for (int j = c; j < c2; j++) {
				int r2 = RandomInRange(b.dices[i][j].m, b.dices[i][j].M);
				a.hp_damage(r2);
				a.stagger_damage(r2);
				cout << "Character a hp deplete: " << r2 << endl;
			}
		}
	}
}

int main() {
	srand(time(0));
	Character a;
	Character b;
	vector <Dice> d1;
	a.print();
	b.print();
	cout << endl;
	Dice a1(1, 1, 6);
	Dice b1(2, 1, 6);
	Dice c1(3, 1, 6);
	d1.push_back(a1);
	d1.push_back(b1);
	d1.push_back(c1);
	a.dices_import(d1);
	b.dices_import(d1);
	while (a.hp > 0 && b.hp > 0) {
		clash(a, b);
		cout << endl;
		a.print();
		b.print();
		cout << endl;
	}
	if (a.hp <= 0) {
		cout << "Character a is dead" << endl;
	}
	else {
		cout << "Character b is dead" << endl;
	}
}