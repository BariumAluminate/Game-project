#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	srand(time(0));
	for (int i = 0; i < n; i++) {
		int dice = rand() % 6 + 1;
		cout << dice << " ";
		sum += dice;
	}
	cout << sum << endl;
}