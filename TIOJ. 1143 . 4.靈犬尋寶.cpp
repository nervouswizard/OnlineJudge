#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[5]={0,0,-1,0,1}, dy[5]={0,1,0,-1,0}, cx[9]={0,1,-1,-3,-3,-1,1,3,3}, cy[9]={0,3,3,1,-1,-3,-3,1,-1};
int G[105][105], Sx, Sy, Ex, Ey, f, fgo;
struct T{
	int x, y, f;
};
int check(int x, int y){
	if (x<=99&&x>=0&&y<=99&&y>=0&&G[x][y]==2) return 2;
	else if (x<=99&&x>=0&&y<=99&&y>=0&&G[x][y]==0) return 0;
	else return 1;
}
void bfs(){
	queue<T>q; q.push(T{Sx, Sy, 0}); G[Sx][Sy]=2;
	while (!q.empty()){
		auto v=q.front(); q.pop(); f=v.f;
		if (v.x==Ex&&v.y==Ey){fgo=f; break;}
		for (int i=1;i<=4;++i)
			if (check(v.x+dx[i], v.y+dy[i])!=1){
				if (!check(v.x+cx[2*i], v.y+cy[2*i])) q.push(T{v.x+cx[2*i], v.y+cy[2*i], f+1}), G[v.x+cx[2*i]][v.y+cy[2*i]]=2;
				if (!check(v.x+cx[2*i-1], v.y+cy[2*i-1])) q.push(T{v.x+cx[2*i-1], v.y+cy[2*i-1], f+1}), G[v.x+cx[2*i-1]][v.y+cy[2*i-1]]=2;
			}
	}
	while (!q.empty()) q.pop();
}
int main(){
	int n, d1, d2;
	cin >> n;
	memset(G,0,sizeof(G));
	for (int i=0;i<n;i++)	cin >> d1 >> d2, G[d1][d2]=1; 
	cin >> Sx >> Sy >> Ex >> Ey;
	bfs();
	if (fgo) cout << fgo << "\n";
	else cout << "impossible\n";
}
