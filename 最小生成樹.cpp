#include<iostream>
#include<algorithm>
using namespace std;
long long boss[200001], Rank[200001], p;
void init(){
	for (long long i=0;i<200001;i++) boss[i]=i, Rank[i]=1;
	p = 0;
}
long long query(long long x){
	if (boss[x]==x) return x;
	return boss[x] = query(boss[x]);
}
void Union(long long a, long long b){
	a = query(a), b = query(b);
	if (a==b) return;
	if (Rank[a]<Rank[b]) boss[a]=b, ++p;
	else if (Rank[a]>Rank[b]) boss[b]=a, ++p;
	else boss[a]=b,++Rank[a], ++p;
}
struct tree{
	long long i, j, c;
	bool operator<(const tree &t)const{
		return c < t.c;
	}
} e[200001];

int main(){
	long long n, m, c, d, sum;
	while (cin >> n >> m){
		init(), sum = 0;
		for (long long k=0;k<m;k++)	cin >> e[k].i >> e[k].j >> e[k].c; 
		sort (e, e+m), sum = 0;
		for (long long k=0;k<m;k++){
			c = query(e[k].i), d = query(e[k].j);
			Union(e[k].i, e[k].j);
			if (query(e[k].i) != c || query(e[k].j) != d)	sum += e[k].c;
		}
		if (p!=n-1)
			cout << -1 << "\n";
		else cout << sum << "\n";
	}
}
