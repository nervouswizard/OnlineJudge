#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
typedef pair<int,int> pii;
int bx[5]={0,0,-1,0,1}, by[5]={0,1,0,-1,0}, dx[9]={0,1,-1,-3,-3,-1,1,3,3}, dy[9]={0,3,3,1,-1,-3,-3,-1,1};
int n, d1, d2, B1, B2, E1, E2, ans;
int dis[105][105];
struct T
{
	int x, y, f;
};
int check(int x, int y)
{
	if (dis[x][y]==2) return 2;
	else if (x>99||x<0||y>99||y<0||dis[x][y]==1) return 1;
	else return 0;
}
void bfs()
{
	queue<T> q; q.push(T{B1, B2, 0});
	dis[B1][B2]=2;
	while (!q.empty())
	{
		T vis=q.front(); q.pop();
		if (vis.x==E1&&vis.y==E2) 
		{
			ans=vis.f;
			break;
		}
		for (int i=1;i<=4;i++)
		{
			if (check(vis.x+bx[i], vis.y+by[i])!=1)
			{
				if (check(vis.x+dx[2*i-1], vis.y+dy[2*i-1])==0)
				{
					q.push(T{vis.x+dx[2*i-1], vis.y+dy[2*i-1], vis.f+1});
					dis[vis.x+dx[2*i-1]][vis.y+dy[2*i-1]]=2;
				}
				if (check(vis.x+dx[2*i], vis.y+dy[2*i])==0)
				{
					q.push(T{vis.x+dx[2*i], vis.y+dy[2*i], vis.f+1});
					dis[vis.x+dx[2*i]][vis.y+dy[2*i]]=2;
				}
			}
		}
	}
}
int main()
{ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> d1 >> d2;
		dis[d1][d2]=1;
	}
	cin >> B1 >> B2 >> E1 >> E2;
	bfs();
	if (ans==0) cout << "impossible\n";
	else cout << ans << "\n";
} 
