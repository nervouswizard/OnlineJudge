#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
struct T{
	long long a, b, c;
	bool operator<(const T &New)const{
		return c<New.c;
	}
};
typedef pair<long long ,long long> pii;
vector<pii> v2[1005];
vector<T> v; 
long long n, m, d1, d2, d3, t, Min, Min2=2147483647, bo1, Max_edge, boss[1005], in[1005], out[1005], ac[12][1005], MAE[12][1005];
long long query(long long x){
	if (boss[x]==x) return x;
	return boss[x]=query(boss[x]);
}
long long Union(long long a, long long b, long long c){
	if ((a=query(a))==(b=query(b))) return c;
	return boss[a]=b,Min+=c,v2[a].push_back({b, c}),v2[b].push_back({a, c}),-1;
}
void dfs(long long x, long long f, long long c){
	in[x]=++t,ac[0][x]=f,MAE[0][x]=c;
	for (auto i:v2[x])	if (i.F!=f)	dfs(i.F, x, i.S);
	out[x]=t;
}
bool check(long long a,long long b){
	return in[a] <= in[b] && out[a] >= out[b];
}
long long LCA(long long a, long long b){
	if (check(a, b)) return 0;
	for (long long i=(Max_edge=0, 10);i>=0;i--)	if (!check(ac[i][a], b)) Max_edge=max(Max_edge, MAE[i][a]), a=ac[i][a];
	return max(Max_edge, MAE[0][a]);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for (long long i=(cin >> n >> m,1);i<=n;i++) boss[i]=i;
	for (long long i=0;i<m;i++)cin >> d1 >> d2 >> d3,v.push_back({d1, d2, d3});
	for (long long i=(sort(v.begin(), v.end()),0);i<m;i++)v[i].c=Union(v[i].a, v[i].b, v[i].c);
	for (long long i=(dfs(1, 1, 0),1);i<11;i++)for (long long j=1;j<=n;j++)ac[i][j]=ac[i-1][ac[i-1][j]],MAE[i][j]=max(MAE[i-1][j], MAE[i-1][ac[i-1][j]]);
	for (int i=0;i<m;i++)if (v[i].c!=-1)Min2=min(Min2, v[i].c-max(LCA(v[i].a, v[i].b), LCA(v[i].b, v[i].a)));
	for(int i=1;i<n;i++) if (query(i)!=query(i+1)) bo1=1;
	(bo1==1)?cout << "-1 -1":(m==n-1)?cout << Min << " -1":cout << Min << " " << Min+Min2;
} 
