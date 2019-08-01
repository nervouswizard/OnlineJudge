#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define MP make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
struct T
{
	int l, r, c, f;
};
int dx[6]={-1,1,0,0,0,0}, dy[6]={0,0,1,-1,0,0}, dz[6]={0,0,0,0,1,-1};
int l, r, c, ans;
int d[35][35][35];
char ch;
T B, E;
void build(T d1, int d2, int d3, int d4)
{
	d1.l=d2, d1.r=d3, d1.c=d4;
}
int check(int d1, int d2, int d3)
{
	if (d1>0&&d2>0&&d3>0&&d1<=l&&d2<=r&&d3<=c) return 1;
	return 0;
}
void bfs()
{
	int f;
	queue<T> q; q.push(B);
	while (!q.empty())
	{
		T n=q.front(); q.pop();
		f=n.f;
		for (int i=0;i<6;i++)
		{
			T v={n.l+dx[i], n.r+dy[i], n.c+dz[i], f+1};
			if (d[v.l][v.r][v.c]==0)
			{
				q.push(v);
				d[v.l][v.r][v.c]=1;
			}
			if (v.l==E.l&&v.r==E.r&&v.c==E.c)
				ans=v.f;
		}
	}
}
int main()
{jizz
	while (cin >> l >> r >> c, l+r+c)
	{
		ans=0;
		for (int i=0;i<=l+1;i++)
		{
			for (int j=0;j<=r+1;j++)
			{
				for (int k=0;k<=c+1;k++)
				{
					if (check(i, j, k))
					{
						cin >> ch;
						if (ch=='S') B=T{i, j, k, 0}, d[i][j][k]=1;
						else if (ch=='E') E=T{i, j, k, 0}, d[i][j][k]=0;
						else if (ch=='.') d[i][j][k]=0;
						else d[i][j][k]=1;
					}
					else d[i][j][k]=1;
				}
			}
		}
		bfs();
		if (ans==0) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}
} 
