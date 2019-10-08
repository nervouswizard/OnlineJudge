#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) x&-x
#define F first 
#define S second 
#define pb push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll INF=1e9;
const ll MAXN=1e6;
ll t, n, d, ans;
ll a[MAXN+5];
stack<ll> s;
void f(ll x, ll y)
{
	ll cnt=0;
	while (s.size()&&s.top()==x)
		s.pop(), cnt++;
	if (!s.size())
		for (ll i=0;i<cnt;i++)
			ans+=i+1;
	else 
		for (ll i=0;i<cnt;i++)
			ans+=i+2;
	if (s.size()&&s.top()<y) f(s.top(), y);
}
void f2(ll x)
{
	ll cnt=0;
	while (s.size()&&s.top()==x)
		s.pop(), cnt++;
	if (s.size())
		for (ll i=0;i<cnt;i++)
			ans+=i+1;
	else 
		for(ll i=0;i<cnt;i++)
			ans+=i;
	if (s.size()) f2(s.top());
}
int main()
{jizz
	cin >> t;
	while (t--)
	{
		ans=0;
		while (s.size()) s.pop();
		cin >> n >> a[0];
		s.push(a[0]);
		for (ll i=1;i<n;i++)
		{
			cin >> a[i];
			if (a[i]>a[i-1]) 
				f(a[i-1], a[i]);
			s.push(a[i]);
		}
		if (s.size())
			f2(s.top());
		cout << ans << "\n";
	}
}
