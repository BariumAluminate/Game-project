#include <iostream>
#include <vector>
#include <cmath>
#include "Header.h"

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
		cout << "Dice type: " << offensive << endl;
		cout << "Dice range: " << m << " - " << M << endl;
	}
};