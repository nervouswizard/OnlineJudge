#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll; 
typedef pair<int,int> pii;
const ll MAXN=1e5+5;
const ll MAXSEG=1e6+1;
struct rectangle{
	ll b, d, u, boo;
};
rectangle a[MAXN*2];
pii seg[MAXSEG*4];
ll n, d1, d2, d3, d4, ans, maxu;
bool cmp(rectangle a, rectangle b){
	return a.b < b.b;
}
void modify(ll qd, ll qu, ll d, ll u, ll rt, ll boo){
	if (qd<=d&&qu>=u) return seg[rt].F+=boo, void();
	ll m=d+u>>1;
	if (m>=qu) modify(qd, qu, d, m, rt<<1, boo);
	else if (m<qd) modify(qd, qu, m+1, u, rt<<1|1, boo);
	else modify(qd, qu, d, m, rt<<1, boo), modify(qd, qu, m+1, u, rt<<1|1, boo);
	seg[rt].S=0;
	if (seg[rt<<1].F>=1) seg[rt].S+=m-d+1;
	else seg[rt].S+=seg[rt<<1].S;
	if (seg[rt<<1|1].F>=1) seg[rt].S+=u-m;
	else seg[rt].S+=seg[rt<<1|1].S;	
}
int main(){
	cin >> n;
	for (ll i=0;i<n*2;i++){
		cin >> d1 >> d2 >> d3 >> d4;
		maxu=max(maxu, d4);
		a[i].b=d1, a[i].d=d3, a[i].u=d4, a[i].boo=1;
		a[++i].b=d2, a[i].d=d3, a[i].u=d4, a[i].boo=-1;
	}
	sort(a, a+n*2, cmp);
	for (ll i=0;i<2*n;i++){
		if(i>0) ans+=(seg[1].S)*(a[i].b-a[i-1].b)/*, cout << a[i-1].b << " " << a[i].b << " "*/;
//		cout << ans << " ";
		modify(a[i].d+1, a[i].u, 0, maxu+1, 1, a[i].boo);
//		cout << seg[1].S << "\n";
	}
	cout << ans;
}
