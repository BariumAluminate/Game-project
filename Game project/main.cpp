#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Header.h"
#include "Card.h"
#include "Character.h"

using namespace std;

vector <Card> deck;
const Card nothing(0,0);

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Card_import(deck);

	Character Player;
	Character Enemy;
	
	Player.name = "Player";
	Enemy.name = "Enemy";

	Enemy.energy = 99999;

	Player.card_draw(nothing);
	Enemy.card_draw(nothing);

	for (int i = 0; i < 5; i++) {
		Player.card_draw(deck[rand() % deck.size()]);
		Enemy.card_draw(deck[rand() % deck.size()]);
	}
	
	while (true) {
		cout << endl;
		Player.print();
		cout << endl;
		Enemy.print();
		cout << endl;
		int number_card1=0;
		if (Enemy.stagger > 0) {
			cout << "Enemy choose a card " << endl;
			int l = Enemy.hand.size();
			number_card1 = RandomInRange(1, l);
			cout << number_card1 << endl;
			Enemy.card_option(number_card1);
			cout << "Information :" << endl;
			Enemy.hand[number_card1].print();
			cout << endl;
		}
		else {
			cout << "Enemy is staggered" << endl;
		}

		int number_card2=0;
		cout << "Card in your deck: " << endl;
		Player.card_show();
		if (Player.stagger > 0) {
			cout << "It's your turn to choose a card " << endl;
			cin >> number_card2;
			Player.card_option(number_card2);
			
		}
		else {
			cout << "You are staggered" << endl;
		}
		if (Player.stagger > 0 && Enemy.stagger > 0) {
			cout << "Clash begin: " << endl;
			clash(Player, Enemy, number_card2, number_card1);
		}
		if (Player.stagger == 0 && Enemy.stagger > 0) {
			cout << "Enemy attack you: " << endl;
			one_side_clash(Enemy, Player, number_card1);
		}
		if (Player.stagger > 0 && Enemy.stagger == 0) {
			cout << "You attack enemy: " << endl;
			one_side_clash(Player, Enemy, number_card2);
		}
		if (Player.stagger == 0 && Enemy.stagger == 0) {
			cout << "Both are staggered" << endl;
			continue;
		}

		Player.energy -= Player.hand[number_card2].energy_consumption;
		Enemy.energy -= Enemy.hand[number_card1].energy_consumption;

		if (number_card2 != 0) {
			Player.card_discard(number_card2);
		}
		Player.card_draw(deck[rand() % deck.size()]);
		Player.energy++;
		Enemy.energy++;

		if (Player.hp <= 0) {
			cout << "You lose" << endl;
			break;
		}
		if (Enemy.hp <= 0) {
			cout << "You win" << endl;
			break;
		}
	}
}