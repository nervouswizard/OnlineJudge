#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
	int a, b, w;
	bool operator<(const edge &a)const{
		return w<a.w;
	} 
};
int boss[10005], Rank[10005], sum, ma;
vector<edge> G;
int query(int x){
	if (boss[x]==x) return x;
	else return boss[x]=query(boss[x]);
}
void Union(int a, int b, int w){
	a=query(a), b=query(b);
	if (a==b) return;
	else boss[a]=b;
	sum+=w;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m, d1, d2, d3;
	while (cin >> n >> m, n+m){
		G.clear();
		sum=0, ma=0;
		for (int i=1;i<=n;i++) boss[i]=i, Rank[i]=1;
		for (int i=1;i<=m;i++){
			cin >> d1 >> d2 >> d3;
			G.push_back(edge{d1, d2, d3});
		}
		sort(G.begin(), G.end());
		for(int i=0;i<m;i++){
			Union(G[i].a, G[i].b, G[i].w);
		}
		for (int i=1;i<=n;i++) query(i);
		for (int i=2;i<=n;i++) if (boss[i]!=boss[i-1]) sum=-1;
		cout << sum << "\n";
	}
} 
