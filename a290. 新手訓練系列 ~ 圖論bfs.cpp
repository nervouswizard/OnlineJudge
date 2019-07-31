#include<bits/stdc++.h>
using namespace std;
vector<int>G[805];
int a, b, ans, vis[10005];
void bfs(int u){
	queue<int> q;q.push(u),vis[u]=1;
	while(!q.empty()){
		int v=q.front(); q.pop();
		if (v==b) ans=1;
		for(int i:G[v]) if(!vis[i]) q.push(i), vis[i]=1;
	}
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
		cin >> a >> b, bfs(a);
		if (ans == 1) cout << "Yes!!!\n";
		else cout << "No!!!\n";
		for (int i=1;i<=n;i++)G[i].clear(), vis[i] = 0;
	}
}
