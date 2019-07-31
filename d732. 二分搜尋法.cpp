#include<iostream>

using namespace std;

int main(){
	int n, k, a[100100], b, c, d, m;
	while (cin >> n >> k){
		for (int i = 1; i <= n; i++) cin >> a[i];
		while (k--){
			cin >> b;
			c = 1, d = n;
			while (d > c){
				m = (d + c) / 2;
				if (a[m] >= b) d = m;
				else c = m + 1;
			}
			if (b == a[c])
				cout << c << "\n";
			else
				cout << 0 << "\n";
			
		}
	}
} 
