#include <iostream>
#include <vector>
#include <cmath>
#include "Header.h"
#include "Player.h"

const int max_dice = 3;

class Dice
{
public:
	int offensive; // 0 - defensive, !0 - offensive: 1 - slash, 2 -pierce, 3 - blunt; -1 - no dice
    int m, M;
    Dice() {
        offensive = -1;
        m = 0;
        M = 0;
    }
    Dice(int offensive, int m, int M) {
        this->offensive = offensive;
        this->m = m;
        this->M = M;
    }
	void print() const {
		cout << "Dice type: " << offensive << endl;
		cout << "Dice range: " << m << " - " << M << endl;
	}
};


class Card
{
public:
	int dice_size;
	Card() {
		dice_size = 0;
	}
	vector <Dice> dices;
	void add_dice(Dice dice) {
		dices.push_back(dice);
		dice_size++;
	}
};

class SpeedDice
{
public:
	int m,M;
	int using_card;
	SpeedDice() {
		m = 0;
		M = 0;
		using_card = 0;
	}
	SpeedDice(int m, int M, int using_card) {
		this->m = m;
		this->M = M;
		this->using_card = using_card;
	}
};