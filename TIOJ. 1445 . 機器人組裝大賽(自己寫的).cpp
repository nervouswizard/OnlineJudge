#include<iostream>
#include<vector>
#include<algorithm>
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
long long n, m, d1, d2, d3, t, Min, bo1, bo2;
long long boss[1005], in[1005], out[1005], ac[12][1005], MAE[12][1005];
long long query(long long x){
	if (boss[x]==x) return x;
	return boss[x]=query(boss[x]);
}
long long Union(long long a, long long b, long long c){
	a=query(a), b=query(b);
	if (a==b) return c;
	boss[a]=b;
	Min+=c;
	v2[a].push_back({b, c});
	v2[b].push_back({a, c});
	return -1;
}
void dfs(long long x, long long f, long long c){
	in[x]=++t;	ac[0][x]=f;	MAE[0][x]=c;
	for (auto i:v2[x]){
		if (i.F!=f){
			dfs(i.F, x, i.S);
		}
	}
	out[x]=t;
}
long long check(long long a,long long b){
	if (in[a] <= in[b] && out[a] >= out[b]) return 1;
	return 0;
}
long long LCA(long long a, long long b){
	long long Max_edge=0;
	if (check(a, b)) return 0;
	for (long long i=10;i>=0;i--)
		if (!check(ac[i][a], b)) Max_edge=max(Max_edge, MAE[i][a]), a=ac[i][a];
	return max(Max_edge, MAE[0][a]);
}
int main(){
	cin >> n >> m;
	for (long long i=1;i<=n;i++) boss[i]=i;
	for (long long i=0;i<m;i++){
		cin >> d1 >> d2 >> d3;
		v.push_back({d1, d2, d3});
	}
	sort(v.begin(), v.end());
	for (long long i=0;i<m;i++){
		v[i].c=Union(v[i].a, v[i].b, v[i].c);
	}
	dfs(1, 1, 0);
	for (long long i=1;i<11;i++)
		for (long long j=1;j<=n;j++){
			ac[i][j]=ac[i-1][ac[i-1][j]];
			MAE[i][j]=max(MAE[i-1][j], MAE[i-1][ac[i-1][j]]);
		}
	long long Min2=2147483647;
	for (long long i=0;i<m;i++){
		if (v[i].c!=-1){
			d1=LCA(v[i].a, v[i].b);
			d2=LCA(v[i].b, v[i].a);
			d3=max(d1, d2);
			Min2=min(Min2, v[i].c-d3);
		} 
	}
	for(int i=1;i<n;i++) if (query(i)!=query(i+1)) bo1=1;
	if (m==n-1) bo2=1;
	if (bo1==1) cout << "-1 -1";
	else if (bo2==1) cout << Min << " -1";
	else cout << Min << " " << Min+Min2;
} 
