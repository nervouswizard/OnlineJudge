#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
int dx[6]={-1,1,0,0,0,0}, dy[6]={0,0,1,-1,0,0}, dz[6]={0,0,0,0,1,-1};
int d[35][35][35], L, c, r, foo=0, Si, Sj, Sk, Ei, Ej, Ek;
struct Av{
	int x, y, z, f;
};
void bfs(){
	int f;
	queue<Av>q; q.push(Av{Si, Sj, Sk, 0}); 
	d[Si][Sj][Sk]=1; 
	foo=0;
	while (!q.empty()){
		Av v=q.front();q.pop();f=v.f;
		for (int i=0;i<6;++i){
			if (!d[v.x+dx[i]][v.y+dy[i]][v.z+dz[i]]){
				q.push(Av{v.x+dx[i], v.y+dy[i], v.z+dz[i], f+1});
				d[v.x+dx[i]][v.y+dy[i]][v.z+dz[i]]=1;
			}
			if (v.x+dx[i]==Ei&&v.y+dy[i]==Ej&&v.z+dz[i]==Ek) {foo=f; break;}
		}
	}
	while (!q.empty()) q.pop();
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	char ch;
	memset(d,0,sizeof(d));
	while(cin >> L >> r >> c, L+r+c){
		for (int i=0;i<=L+1;++i){					
			for (int j=0;j<=r+1;++j)				
				for (int k=0;k<=c+1;++k){			
					if(i>0&&j>0&&k>0&&i<=L&&j<=r&&k<=c)	{
						cin >> ch;
						if (ch=='S')	d[i][j][k]=0, Si=i, Sj=j, Sk=k;
						else if (ch=='#')	d[i][j][k]=1;
						else if (ch=='.')	d[i][j][k]=0;
						else d[i][j][k]=0, Ei=i, Ej=j, Ek=k;
					}
					else d[i][j][k]=1;
				}
		}
		bfs();
		cout << (foo!=0?"Escaped in "+to_string(foo+1)+" minute(s).\n":"Trapped!\n");
	}
}
