#include <iostream>
#include <cstdlib>
using namespace std;

int RandomInRange(int minn, int maxx) {
	srand(time(0));
	int r = rand() % (maxx - minn + 1) + minn;
	return r;
}