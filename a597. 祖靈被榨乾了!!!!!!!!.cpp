#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
int G[505][505], f, jizz, foo;
struct T{
	int y, x;
};
void bfs(int y, int x){
	queue<T>q; q.push(T{y, x}), f=0, jizz++;
	while (!q.empty()){
		auto v=q.front(); q.pop();
		for (int i=0;i<4;++i){
			if (!G[v.y+dy[i]][v.x+dx[i]]){
				q.push(T{v.y+dy[i], v.x+dx[i]});
				G[v.y+dy[i]][v.x+dx[i]]=-1;
				f++;
			}
		}
	}
	foo=max(foo, f);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	char c;
	while (cin >> m >> n){
		jizz=0, foo=0;
		memset(G,-1,sizeof(G));
		for (int i=1;i<=m;++i)		
			for (int j=1;j<=n;++j){	
				cin >> c; if (c=='J') G[i][j]=0; 
			}
		for (int i=1;i<=m;++i)	
			for (int j=1;j<=n;++j)
				if (!G[i][j]) bfs(i, j);
		cout << jizz <<" "<< foo << "\n";
	}
}
