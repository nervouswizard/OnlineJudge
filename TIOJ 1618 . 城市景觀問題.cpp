#include<bits/stdc++.h>
#define F first
#define S second
#define INF 2147483647
using namespace std;
typedef pair<long,long> pll;
deque<pll>de;
pll a[500005];
long long n, k, ans, Max=-INF, q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for (int i=0;i<n;i++)
		cin >> a[i].F;
	for (int i=0;i<n;i++)
		cin >> a[i].S;
	for (int i=0;i<n;i++){
		int t=0;
		while (!de.empty()&&de.back().F<a[i].F) ans-=de.back().S, de.pop_back(), t++;
		while (t--) de.push_back({0,0});
		de.push_back(a[i]);
		ans+=de.back().S;
		if (i>=k) ans-=de[0].S, de.pop_front();
		if (ans>Max) Max=ans, q=i; 
		cout << ans << " ";
	} 
//	for (int i=0;i<n;i++) cout << de[i].F << " ";
	cout << q+1 << " " << Max;
}
