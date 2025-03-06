#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "Header.h"
using namespace std;

class dice
{
public:
    int offensive; // 0 - defensive, !0 - offensive: 1 - slash, 2 -pierce, 3 - blunt; (-1) - no dice
    int m, M;
    dice() {
        offensive = -1;
        m = 0;
        M = 0;
    }
    dice(int offensive, int m, int M) {
        this->offensive = offensive;
        this->m = m;
        this->M = M;
    }
    void print() const {
		cout << "\t";
        cout << "dice type: ";
		if (offensive == 0) cout << "Defensive" << '\t';
		else if (offensive == 1) cout << "Slash" << '\t';
		else if (offensive == 2) cout << "Pierce" << '\t';
		else if (offensive == 3) cout << "Blunt" << '\t';
		else cout << "No dice" << '\t';
        cout << "dice range: " << m << " - " << M << endl;
    }
	int clash(const dice& other) const {
		int r1 = RandomInRange(m, M);
		int r2 = RandomInRange(other.m, other.M);
		if (r1 > r2) return r1;
		else if (r1 < r2) return -r2;
		else return 0;
	}
	int one_side_clash() const {
		return RandomInRange(m, M);
	}
};

class card
{
public:
	int energy_consumption;
	int dice_number;
	vector <dice> dices;
	card() {
		energy_consumption = 0;
		dice_number = 0;
	}
	card(int energy_consumption, int dice_number) {
		this->energy_consumption = energy_consumption;
		this->dice_number = dice_number;
	}
	card(int energy_consumption, int dice_number, vector <dice> dices) {
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

	void dice_import(dice a) {
		dices.push_back(a);
	}
};