#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> g[40005];
int n, m, a, b, ans;
int vis[40005];
void init()
{
	ans=0;
	for (int i=0;i<40005;i++)
	{
		vis[i]=2;
		g[i].clear();
	}
}
void dfs(int x, int c)
{
	vis[x]=c;
	for (int i:g[x])
	{
		if (vis[i]==c) ans=1;
		if (vis[i]==2) dfs(i, c^1);
	}
}
int main()
{
	while (cin >> n >> m, n+m)
	{
		init();
		for (int i=0;i<m;i++)
		{
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		for (int i=1;i<=n;i++) 
			if (vis[i]==2)
				dfs(i, 0);
		cout << (ans==0?"Yes\n":"No\n");
	}
} 
