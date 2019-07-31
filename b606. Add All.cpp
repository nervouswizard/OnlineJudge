#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
	long long n, a, c, d, e, fuck;
	while (cin >> n, n){
		while (!pq.empty()) pq.pop(); 
		for (int i = 0; i < n; i++){
			cin >> a;
			pq.push(a);
		}
		fuck = 0;
		while (pq.size() != 1){
			c = pq.top(), pq.pop();
			d = pq.top(), pq.pop();
			e = c + d;
			pq.push(e);
			fuck += e;
		}
		cout << fuck << "\n";
	}
} 
