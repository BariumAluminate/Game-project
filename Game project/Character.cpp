#include "Character.h"
#include "Header.h"
using namespace std;

void Character::card_option(int& number_card) {
	while (number_card <= 0 || number_card >= hand.size()) {
		cout << "Invalid card number, please choose again: ";
		cin >> number_card;
	}
	while (hand[number_card].energy_consumption > energy) {
		cout << "Not enough energy, please choose again: ";
		cin >> number_card;
	}
}

void clash(Character& a, Character& b, int numbercard1, int numbercard2) {
	Card card1 = a.hand[numbercard1];
	Card card2 = b.hand[numbercard2];
	int m = min(card1.dice_number, card2.dice_number);
	for (int i = 0; i < m; i++) {
		int clashpowera = RandomInRange(card1.dices[i].m, card1.dices[i].M);
		int clashpowerb = RandomInRange(card2.dices[i].m, card2.dices[i].M);
		if (clashpowera > clashpowerb) {
			cout << a.name << " win this clash" << endl;
			cout << "Damage dealt: " << clashpowera - clashpowerb << endl;
			b.hp_damage(clashpowera - clashpowerb);
		}
		else if (clashpowera < clashpowerb) {
			cout << b.name << " win this clash" << endl;
			cout << "Damage dealt: " << clashpowerb - clashpowera << endl;
			a.hp_damage(clashpowerb - clashpowera);
		}
	}
	if (card1.dice_number > card2.dice_number) {
		int n = card1.dice_number - card2.dice_number;
		for (int i = m; i < n; i++) {
			int clashpowera = RandomInRange(card1.dices[i].m, card1.dices[i].M);
			b.hp_damage(clashpowera);
		}
	}
	if (card1.dice_number < card2.dice_number) {
		int n = card2.dice_number - card1.dice_number;
		for (int i = m; i < n; i++) {
			int clashpowerb = RandomInRange(card2.dices[i].m, card2.dices[i].M);
			a.hp_damage(clashpowerb);
		}
	}
}