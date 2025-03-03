#include "Card.h"
#include <iostream>
#include <fstream>
using namespace std;

void Card_import(vector <Card>& data) {
	ifstream f1("CardData.txt");
	if (!f1.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	while (!f1.eof()) {
		Card a;
		f1 >> a.dice_number >> a.energy_consumption;
		for (int i = 0; i < a.dice_number; i++) {
			Dice b;
			f1 >> b.offensive >> b.m >> b.M;
			a.dice_import(b);
		}
		data.push_back(a);
	}
}