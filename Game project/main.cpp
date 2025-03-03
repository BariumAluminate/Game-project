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

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Card_import(deck);

	Character Player;
	Character Enemy;
	
	Player.name = "Player";
	Enemy.name = "Enemy";

	Enemy.energy = 99999;

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
		
		cout << "Enemy choose a card " << endl;
		int l = Enemy.hand.size();
		int number_card1=RandomInRange(1, l);
		Enemy.card_option(number_card1);
		cout << "Information :" << endl;
		Enemy.hand[number_card1].print();
		cout << endl;

		int number_card2;
		cout << "Card in your deck: " << endl;
		Player.card_show();
		cout << "It's your turn to choose a card " << endl;
		cin >> number_card2;
		Player.card_option(number_card2);
		cout << "Clash begin: " << endl;
		clash(Player, Enemy, number_card1,number_card2);

		Player.energy -= Player.hand[number_card2].energy_consumption;
		Enemy.energy -= Enemy.hand[number_card1].energy_consumption;

		Enemy.card_discard(number_card1);
		Player.card_discard(number_card2);
		Enemy.card_draw(deck[rand() % deck.size()]);
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