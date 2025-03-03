#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Header.h"
using namespace std;

const int max_dice = 3;

class Dice
{
public:
    int offensive; // 0 - defensive, !0 - offensive: 1 - slash, 2 -pierce, 3 - blunt; (-1) - no dice
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
		cout << "\t";
        cout << "Dice type: ";
		if (offensive == 0) cout << "Defensive" << '\t';
		else if (offensive == 1) cout << "Slash" << '\t';
		else if (offensive == 2) cout << "Pierce" << '\t';
		else if (offensive == 3) cout << "Blunt" << '\t';
		else cout << "No dice" << '\t';
        cout << "Dice range: " << m << " - " << M << endl;
    }
};

class Card
{
public:
	int energy_consumption;
	int dice_number;
	vector <Dice> dices;
	Card() {
		energy_consumption = 0;
		dice_number = 0;
	}
	Card(int energy_consumption, int dice_number, vector <Dice> dices) {
		this->energy_consumption = energy_consumption;
		this->dice_number = dice_number;
		this->dices = dices;
	}
	void print() const {
		cout << "\t";
		cout << "Energy consumption: " << energy_consumption << endl;
		cout << "\t";
		cout << "Number of dices: " << dice_number << endl;
		for (int i = 0; i < dice_number; i++) {
			dices[i].print();
		}
	}

	void dice_import(Dice a) {
		dices.push_back(a);
	}
};

void Card_import(vector <Card>& data);

#endif