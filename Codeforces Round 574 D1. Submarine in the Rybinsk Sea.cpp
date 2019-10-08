#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0);
#define F first 
#define S second
#define pb push_back
#define MP make_pair
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> pii;
const ll inf=1e9+7;
const ll mod=998244353;
const ll maxn=1e5+5;
ll n, ans, t;
string s[maxn];
int main()
{jizz
	ll d;
	cin >> n;
	ans=0;
	for (ll i=0;i<n;i++)
	{
		cin >> s[i];
		t=1;
		for (int j=s[i].size()-1;j>=0;j--)
		{
			d=(((s[i][j]-'0')*t)%mod*n)%mod;
			ans=(ans+d)%mod;
			d=(d*10)%mod;
			ans=(ans+d)%mod;
			t*=100;
		}
	}
	cout << ans << "\n";
} 
