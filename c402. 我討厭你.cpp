#include<iostream>
#include<vector>
#include<queue> 
using namespace std;
int a[3005], vis[3005];
vector<int> G[3005];
void bfs(){
	queue<int>q; q.push(1); vis[1]=1;
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int i:G[v]){
			
		}
	}
}
int main(){
	int n, m, d1, d2;
	while (cin >> n >> m){
		for (int i=1;i<=n;++i) cin >> a[i];
		for (int i=0;i<m;++i){
			cin >> d1 >> d2;
			G[d1].push_back(d2);
			G[d2].push_back(d1);
		} 
		bfs();
	}
}
