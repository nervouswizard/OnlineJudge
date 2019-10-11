#include <iostream>

using namespace std;

int main() {
	long i, w, h, max, i2, i3;
	while (cin >> i, i != 0) {
		i2 = i;
		for (w = 0, h = 0, max = 0; i > 0; i--) {
			cin >> w >> h;
			if (w * h > max) {
				max = w * h;
				i3 = i2 - i + 1; 
			}
		}
		cout << i3 << endl;
	}
}