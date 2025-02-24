#include <iostream>
#include "Header.h"

class Dice
{
public:
    string Dicetype;
    int m, M;
    Dice() {
        Dicetype = "";
        m = 0;
        M = 0;
    }
    Dice(string Dicetype, int m, int M) {
        this->Dicetype = Dicetype;
        this->m = m;
        this->M = M;
    }
};


class Card
{
public:
    int number;
    Dice* dices;
};