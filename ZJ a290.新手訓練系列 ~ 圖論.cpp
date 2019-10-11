#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pb push_back
using namespace std;
int vis[805];
vector<int> v[805];
void bfs(int x, int dis)
{
	int ans=0;
	queue<int> q; q.push(x), vis[x]=1;
	while (!q.empty())
	{
		int f=q.front(); q.pop();
		if (f==dis) 
		{
			ans=1;
			break;
		}
		for (int i:v[f]) if (!vis[i]) q.push(i), vis[i]=1;
	}
	if (ans==1) cout << "Yes!!!\n";
	else cout << "No!!!\n";
}
int main()
{jizz
	int n, m, d1, d2;
	while (cin >> n >> m)
	{
		for (int i=1;i<=n;i++) v[i].clear(), vis[i] = 0;
		for (int i=0;i<m;i++)
		{
			cin >> d1 >> d2;
			v[d1].pb(d2);
		}
		cin >> d1 >> d2;
		bfs(d1, d2);
	}
}
