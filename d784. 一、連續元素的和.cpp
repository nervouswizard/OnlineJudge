#include<iostream>

using namespace std;

int main(){
	int n, k, data, sum, maxsum;
	cin >> n; 
	while (n--){
		cin >> k;
		while (k--){
			cin >> data;
			if (sum + data < 0) sum = 0;
			else sum+=data;
			maxsum = max(sum, maxsum);
		}
		if (maxsum==0) cout << -1 << "\n";
		else cout << maxsum << "\n";
		maxsum = sum = 0;
	}
}

