#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int vis[40005], d1, d2, fv, ans;
vector <int> G[40005];
void dfs(int u,int vc){
	vis[u]=vc;
	for (int i:G[u]) {
		if (vis[i]==vc) ans = 1;
		if (!vis[i]) dfs(i, vc==1?2:1);
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	while (cin >> n >> m, n+m){
		ans = 0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++) G[i].clear();
		for (int i=0;i<m;i++) cin >> d1 >> d2, G[d1].push_back(d2), G[d2].push_back(d1);
		for (int i=0;i<n;i++) if (!vis[i]) dfs(i, 1);
		cout << (ans==0?"Yes\n":"No\n");
	}
}
