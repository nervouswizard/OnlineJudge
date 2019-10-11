#include<iostream>
#include <algorithm>
#include<deque>

using namespace std;

int main(){
	long long n, q, a[100010], b, j;
	deque<long long>dq;
	cin >> n >> q;
	for (int i=0; i<n; i++)	cin >> a[i];
	sort(a, a+n);
	while (q--){
		cin >> b;
		while(!dq.empty()) dq.pop_front();
		for (j=0; j<n; j++){
			dq.push_back(a[j]);
			while(dq.back()-dq.front()>b) dq.pop_front();
			if(dq.back()-dq.front()==b) {
				cout << "YES\n";
				j = n+1;
			}
		}
		if (j==n) cout << "NO\n";
	}
}
