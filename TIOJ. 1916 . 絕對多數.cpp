#include <bits/stdc++.h>

using namespace std;

int a[2000][2000];

int main(){
	int n, r1, r2, c1, c2, x, y, o;
	srand(time(NULL)); 
	while (cin >> n, n){
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				cin >> a[j][i];
		cin >> n;
		while (n--) {
			cin >> r1 >> r2 >> c1 >> c2;
			if (r1 > r2) o = r1, r1 = r2, r2 = o;
			if (c1 > c2) o = c1, c1 = c2, c2 = o;
			for (int i = 0; i < 8; i++){
				x = (rand() % (r2 - r1 + 1) + r1), y = (rand() % (r2 - r1 + 1) + c1);
				 = a[x][y]
			}
		}
	}
}
