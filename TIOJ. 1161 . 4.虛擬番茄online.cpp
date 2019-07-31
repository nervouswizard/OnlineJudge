#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define F first
#define S second
#define INF 2147483647
using namespace std;
typedef pair <int, int> pii;
int t, n, k, a, s, ans;
vector<pii> v;
priority_queue<int> pq;
int main(){
	cin >> t;
	while(t--){
		v.clear();
		while (!pq.empty()) pq.pop();
		cin >> n >> k, ans=INF;
		for (int i=0;i<n;i++) 
			cin >> a >> s, v.push_back({a, s});
		sort (v.begin(), v.end());
		for (int i=0;i<n;i++){
			pq.push(v[i].S);
			while(pq.size()>k) pq.pop();
			if (pq.size()==k) ans=min(ans, v[i].F+pq.top());
		}
		cout << ans << "\n";
	}
}
