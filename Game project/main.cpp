#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	int minn, maxx;	
	cout << "Enter the minimum value: ";
	cin >> minn;
	cout << "Enter the maximum value: ";
	cin >> maxx;
	cout << "Random number between " << minn << " and " << maxx << " is: " << RandomInRange(minn, maxx) << endl;
	return 0;
}