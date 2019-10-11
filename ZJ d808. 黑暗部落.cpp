#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define LL long long
#define S second
#define F first
using namespace std;
int a[1000005], boss[1000005], Rank[1000005], ma, gr;
int query(int x){
	if (boss[x]==x) return x;
	return boss[x]=query(boss[x]);
}
void Union(int a,int b){
	a=query(a), b=query(b);
	if (a==b) return;
	if (Rank[a]<Rank[b]) boss[a]=b, Rank[b]+=Rank[a], ma=max(ma, Rank[b]);
	else boss[b]=a, Rank[a]+=Rank[b], ma=max(ma, Rank[a]);
} 
int main(){
	int n;
	while (cin >> n){
		ma=0;gr=0;memset(a,0,sizeof(a));memset(boss,0,sizeof(boss));memset(Rank,0,sizeof(Rank));
		for (int i=1;i<=n;++i) cin >> a[i], boss[i]=i, Rank[i]=1;
		for (int i=1;i<=n;++i) Union(i, a[i]);
		for (int i=1;i<=n;i++) query(i);
		sort(boss+1, boss+n+1);
		for (int i=1;i<=n;++i) if (boss[i]!=boss[i-1]) gr++;
		cout << gr << " " << ma << "\n";
	}
}
