#include<bits/stdc++.h>
using namespace std;
vector<int>G[805];
int a, b, ans, vis[10005];
void dfs(int u){
	if (u == b) ans = 1;
	vis[u]=1;
	for (int i:G[u]) if(vis[i] == 0) dfs(i);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	while(cin >> n >> m){
		ans = 0;
		for (int i=0;i<m;i++){
			int c, d;
			cin >> c >> d;
			G[c].push_back(d);
		}
		cin >> a >> b, dfs(a);
		if (ans == 1) cout << "Yes!!!\n";
		else cout << "No!!!\n";
		for (int i=1;i<=n;i++)G[i].clear(), vis[i] = 0;
	}
}
