#include<iostream>
#include <queue>

using namespace std;

int main(){
	int n, a[100001], b, c;
	while (cin >> n){
		for(int i=0;i<n;i++) cin >> a[i];
		b = a[0], c = 0;
		for(int i=1;i<n;i++){
			c = max(c,b-a[i]);
			if (b<a[i]) b = a[i];
		}
		cout << c << "\n"; 
	}
}
