#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0);
#define F first
#define S second
#define pb push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=1e9+7;
const int mod=1e9+7;
const int maxn=150005;
int n, d, maxd, ans, l, r;
pii a[maxn];
void front_move(int i)
{
	a[i].F++, a[i+1].F--;
}
void back_move(int i)
{
	a[i-1].S=1;
	a[i].F++, a[i-1].F--;
	if (a[i-2].S==0&&a[i-1].F==0&&a[i-2].F>0)
		back_move(i-1);
}
int main()
{
	cin >> n;
	maxd=-inf;
	for (int i=0;i<n;i++)
	{
		cin >> d;
		a[d].F++;
		maxd=max(d, maxd);
	}
	for (int i=1;i<=maxd+1;i++)
	{
		if (a[i].F==0)
		{
			if (a[i+1].F>0)
				front_move(i);
			else if (a[i-1].S==0&&a[i-1].F>0&&i!=1)
				back_move(i);
		}
	}
	for (int i=1;i<=maxd+1;i++)
		if (a[i].F>0) 
			ans++;
//		cout << a[i].F << " ";
	cout << ans;
}  
