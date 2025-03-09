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

const card nothing(0, 0);

int main() {
	srand(static_cast<unsigned int>(time(0)));

	card_def();

	Character Player;
	Character Enemy;

	Player.name = "Player";
	Enemy.name = "Enemy";

	Player.hand.push_back(nothing);
	Enemy.hand.push_back(nothing);

	//Trong tuong lai co le se sua phan nay thanh phan chon bai
	//Bat dau build bo bai cho player
	vector <card> player_deck;
	player_deck.push_back(fencing);
	player_deck.push_back(weakslash);
	player_deck.push_back(tripleslash);
	int n1 = player_deck.size();
	for (int i = 0; i < 4; i++) {
		Player.card_draw(player_deck[RandomInRange(0, n1 - 1)]);
	}

	//Phan nay se la 1 data rieng cua enemy
	//Build 1 deck cho enemy
	vector <card> enemy_deck;
	enemy_deck.push_back(fencing);
	enemy_deck.push_back(weakslash);
	enemy_deck.push_back(tripleslash);
	int n2 = enemy_deck.size();
	for (int i = 0; i < 4; i++) {
		Enemy.card_draw(enemy_deck[RandomInRange(0, n2 - 1)]);
	}

	
	//game bat dau
	while (true) {

		//khi bat dau turn moi, nang luong tang 1, rut them 1 la
		Player.card_draw(player_deck[RandomInRange(0, n1 - 1)]);
		Player.energy++;

		//In ra thong so cua ta va dich
		Player.print();
		Enemy.print();
		
		//Phan nay sau nay se buff cho enemy con AI co kha nang chon bai dua tren energy left
		cout << "Enemy card information: " << endl;
		Enemy.hand[1].print();

		//Player chon bai
		cout << "It's your turn to choose a card" << endl;
		Player.card_show();
		int number_card;
		cin >> number_card;
		Player.card_option(number_card);

		//Bat dau clash
		cout << "Now the clash between " << Player.name << " and " << Enemy.name << " begin:"<<endl;
		card_clash(Player, Enemy, Player.hand[number_card], Enemy.hand[1]);

		//Tru nang luong sau khi dung bai
		Player.energy -= Player.hand[number_card].energy_consumption;

		//Bo la bai vua chon, neu vua roi chon la nothing thi ko discard
		if(number_card!=0){
			cout << "Discarding card number " << number_card << endl<<endl;
			Player.card_discard(number_card);
		}

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
