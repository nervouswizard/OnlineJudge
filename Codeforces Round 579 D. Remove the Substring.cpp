#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0);
#define F first
#define S second
#define pb push_back
#define MP make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int inf=1e9+7;
const int mod=1e9+7;
const int maxn=200005;
char s[maxn], t[maxn];
int ls, lt, i, j, ans;
int li[maxn], ri[maxn];
int main()
{
	cin >> s >> t;
	ls=strlen(s);
	lt=strlen(t);
	if (lt==ls) 
		cout << 0 << "\n";
	else 
	{
		while (i<lt)
		{
			if (s[j]==t[i])
			{
				li[i]=j;
				i++;
			}
			j++;
		}
		i=lt-1, j=ls-1;
		while (i>-1)
		{
			if (s[j]==t[i])
			{
				ri[i]=j;
				i--;
			}
			j--;
		}
		ans=max(ri[0], ls-li[lt-1]-1);
		for (int i=0;i<lt-1;i++)
			ans=max(ans, ri[i+1]-li[i]-1);
		cout << ans << "\n";
	} 
}
