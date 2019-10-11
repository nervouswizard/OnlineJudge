#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> v[30005];
int in[30005], out[30005], t, de[30005];
int n, q, ac[16][30005], d1, d2, lca;
void dfs(int x, int f, int d){
	in[x]=++t;
	de[x]=d;
	for (auto &c:v[x]){
		if(c != f){
			ac[0][c]=x;
			dfs(c, x, d+1);
		}
	}
	out[x]=++t;
}
int ancestor(int a, int b){
	if (in[a]<=in[b]&&out[a]>=out[b]) return 1;		//if a¬Obªº¯ª¥ý 
	return 0;
}
int LCA(int a, int b){
	if (ancestor(a,b))return a;
	for (int i=15;i>=0;--i)
		if (!ancestor(ac[i][a], b)) a=ac[i][a];
	return ac[0][a];	
}
int main(){
	ios::sync_with_stdio(false) , cin.tie(0);
	while (cin >> n >> q){	
		t=0;
		for (int i=0;i<30005;i++) v[i].clear();
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(de,0,sizeof(de));
		for (int i=0;i<16;i++){
			memset(ac[i],0,sizeof(ac[i]));
		}
		for(int i=1;i<=n;++i)
			while(cin >> d1, d1)
				v[i].push_back(d1);
		ac[0][1] = 1;
		dfs(1, 1, 0);
		for (int i=1;i<16;i++)
			for (int j=1;j<=n;j++)
				ac[i][j]=ac[i-1][ac[i-1][j]];
		for(int i=0;i<q;i++){
			cin >> d1 >> d2;
			lca=LCA(d1, d2);
			cout << lca << " " << de[d1]+de[d2]-2*de[lca] << "\n";
		} 
	}
} 
