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
#include "Data.hpp"

using namespace std;

vector <card> deck;
const card nothing(0, 0);

int main() {
	srand(static_cast<unsigned int>(time(0)));

	card_def();

	Character Player;
	Character Enemy;

	Player.name = "Player";
	Enemy.name = "Enemy";

	Enemy.energy = 99999;

	Player.card_draw(nothing);
	Enemy.card_draw(nothing);

	while (true) {
		Player.print();
		Enemy.print();
		Player.print();
		int number_card;
		cin >> number_card;
		card_clash(Player, Enemy, Player.hand[number_card], Enemy.hand[1]);
		Player.card_discard(number_card);
		Player.card_option(number_card);
		if (Player.hp <= 0) {
			cout << "You lose!";
			return 0;
		}
		if (Enemy.hp <= 0) {
			cout << "You win!";
			return 0;
		}
	}

}
