#include<iostream>
#include<vector>
#include<algorithm>
struct T{
	int a, b, c;
	bool operator<(const T &New)const{
		return c<New.c;
	}
};
using namespace std;
int n, m, k, d1, d2, d3, Min, Max;
int boss[100005];
vector<T> v;
int query(int x){
	if (boss[x]==x) return x;
	return boss[x]=query(boss[x]);
}
void Union(int a, int b, int c){
	a=query(a); b=query(b);
	if (a==b) return;
	boss[a]=b;
	Min+=c;
}
void Union2(int a, int b, int c){
	a=query(a); b=query(b);
	if (a==b) return;
	boss[a]=b;
	Max+=c;
}
int main(){
	cin >> n >> m >> k;
	v.resize(m);
	for (int i=1;i<=n;i++) boss[i]=i;
	for (int i=0;i<m;i++){
		cin >> d1 >> d2 >> d3;
		v[i].a=d1, v[i].b=d2, v[i].c=d3;
	}
	sort(v.begin(), v.end());
	for (int i=0;i<m;i++){
		Union(v[i].a, v[i].b, v[i].c);
	}
	for (int i=1;i<=n;i++) boss[i]=i;
	for (int i=m-1;i>=0;i--){
		Union2(v[i].a, v[i].b, v[i].c);
	}
	if (Min<=k&&Max>=k) cout << "TAK\n";
	else cout << "NIE\n";
} 
