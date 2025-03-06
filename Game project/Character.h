#pragma once

#include <iostream>
#include <algorithm>
#include "card.h"
using namespace std;

class Character
{
public:
	string name;
	int hp, max_energy, sp, stagger,energy;
	int vmax, vmin;
	int level;
	int res[3];
	vector <card> hand;
	Character() {
		name = "";
		hp = 30;
		max_energy = 3;
		energy = 3;
		level = 1;
		sp = 0;
		stagger = 30;
		vmax = 6;
		vmin = 1;
		res[0] = res[1] = res[2] = 2;
	}
	Character(string name, int hp, int max_energy, int level, int sp, int stagger, int vmax, int vmin, int energy, int res[]) {
		this->name = name;
		this->hp = hp;
		this->max_energy = max_energy;
		this->energy = energy;
		this->level = level;
		this->sp = sp;
		this->stagger = stagger;
		this->vmax = vmax;
		this->vmin = vmin;
		std::copy(res, res + 3, this->res);
	}
	void print() const {
		cout << "Name: " << name << endl;
		cout << "HP: " << hp << endl;
		cout << "Level: " << level << endl;
		cout << "SP: " << sp << endl;
		cout << "Stagger: " << stagger << endl;
		cout << "Speed range:" << vmin << " - " << vmax << endl;
		cout << "Energy left: " << energy << endl;
		cout << "card in hand: "<<hand.size() << endl;
	}
	void hp_damage(int a) {
		hp -= a;
		if (stagger == 0) {
			hp -= a;//when being staggered, the character takes double damage
		}
	}
	void stagger_damage(int a) {
		stagger -= a;//this damage is taken when the character take damage
		if (stagger < 0) {
			stagger = 0;//stagger cannot be negative
		}
	}
	void sp_damage(int a) {
		sp -= a;// max sp is 45, min sp is -45
	}
	void hp_heal(int a) {
		hp += a;
	}
	void stagger_heal(int a) {
		stagger += a;
	}
	void sp_heal(int a) {
		sp += a;
	}
	void card_draw(card a) {
		hand.push_back(a);
	}
	void card_discard(int number_card) {
		hand.erase(hand.begin() + number_card);
	}
	void card_show() {
		for (int i = 0; i < hand.size(); i++) {
			cout << "card number " << i << endl;
			hand[i].print();
		}
	}
	void card_option(int &number_card);
};

void card_clash(Character& a, Character& b, card a1, card b1);