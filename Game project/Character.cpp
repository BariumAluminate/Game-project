#include "Character.h"
#include "Header.h"
using namespace std;

void Character::card_option(int& number_card) {
	while (number_card < 0 || number_card >= hand.size()) {
		cout << "Invalid card number, please choose again: ";
		cin >> number_card;
	}
	while (hand[number_card].energy_consumption > energy) {
		cout << "Not enough energy, please choose again: ";
		cin >> number_card;
	}
}

void card_clash(Character& a, Character& b, card a1, card b1) {
	int n1 = a1.dice_number;
	int n2 = b1.dice_number;
	int i = 0, j = 0;
	while (i < n1 && j < n2) {
		cout << "Your clash power and the enemy's :";
		int damage = a1.dices[i].clash(b1.dices[i]);
		if (damage > 0) {
			cout << a.name << " win the clash;" << endl;
			cout << "Damage dealt:";
			b.hp_damage(damage);
			b.stagger_damage(damage);
			cout << endl;
		}
		if (damage < 0) {
			cout << b.name << " win the clash;" << endl;
			cout << "Damage dealt:";
			a.hp_damage(-damage);
			a.stagger_damage(-damage);
			cout << endl;
		}
		i++;
		j++;
	}
	for (i; i < n1; i++) {
		cout << b.name << " card has no dice against this dice from " << a.name << endl;
		cout << "Damage dealt: ";
		int r = a1.dices[i].one_side_clash();
		cout << r << endl;
		b.hp_damage(r);
		b.stagger_damage(r);
	}
	for (j; j < n2; j++) {
		cout << a.name << " card has no dice against this dice from " << b.name << endl;
		cout << "Damage dealt: ";
		int r = b1.dices[j].one_side_clash();
		cout << r << endl;
		b.hp_damage(r);
		b.stagger_damage(r);
	}
}