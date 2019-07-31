#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue <long long> q;
int f[1000100], cnt[1000100], mx;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	long long n, t, a, b, sum;
	while (cin >> n, n){
	    mx = 0, t = 0;
		for (int i = 0; i < n; i++) cin >> f[i], cnt[f[i]]++, mx = max(mx, f[i]);
		for (int i = 1; i <= mx; i++)
			while(cnt[i]) f[t++] = i, cnt[i]--;
		int i;
		i = n-1, t = 0, sum = 0;
		while(!q.empty()) q.pop();
		while (i--){
			if(!q.empty() && (t >= n || f[t] >= q.front())) a = q.front(), q.pop();
			else a = f[t], t++;
			if(!q.empty() && (t >= n || f[t] >= q.front())) b = q.front(), q.pop();
			else b = f[t], t++;
			sum += (a + b);
			q.push(a+b);
		}
		cout << sum << "\n";
	}
}
