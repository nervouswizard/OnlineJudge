#include<bits/stdc++.h>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n, k, ans;
ll a[300005], c[300005];
pll b[300005];
int con(pll a, pll b)
{
	if (a.S>b.S) return 1;
	return 0;
}
int main()
{
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=MP(i-1,a[i]-a[i-1]);
//		cout << b[i].S << "\n";
	}
	b[1]=MP(1,-1);
	sort(b+1, b+n+1, con);
	for (int i=1;i<k;i++)
	{
		c[i]=b[i].F;
	}
	sort(c+1, c+k);
	for (int i=1;i<k;i++)
	{
//		cout << c[i]<< "\n" ;
		ans+=a[c[i]];
//		cout << ans << "\n";
		ans-=a[c[i]+1];
//		cout << ans << "\n";
	}
	ans-=a[1];
	ans+=a[n];
	cout << ans;
}
