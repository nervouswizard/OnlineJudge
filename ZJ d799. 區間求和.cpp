#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define F first 
#define S second 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll MAXN=500005;
ll n, q, seg[MAXN*4], d1, d2, d3, lazy[MAXN*4];
void build(ll l, ll r, ll rt){
	if (l==r) return cin >> seg[rt], void();
	ll m=(l+r)/2;
	build(l, m, rt<<1), build(m+1, r, rt<<1|1);
	seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
void push_down(ll l, ll r, ll rt){
	if (l==r) return;
	lazy[rt<<1]+=lazy[rt];
	lazy[rt<<1|1]+=lazy[rt];
	seg[rt<<1]+=lazy[rt]*((l+r)/2-l+1);
	seg[rt<<1|1]+=lazy[rt]*(r-((l+r)/2+1)+1);
	lazy[rt]=0;
}
ll query(ll ql, ll qr, ll l, ll r, ll rt){
	if (lazy[rt]!=0) push_down(l, r, rt);
	if (ql<=l&&qr>=r) return seg[rt];
	ll m=(l+r)/2;
	if (m>=qr) return query(ql, qr, l, m, rt<<1);
	if (m<ql) return query(ql, qr, m+1, r, rt<<1|1);
	return query(ql, qr, l, m, rt<<1)+query(ql, qr, m+1, r, rt<<1|1);
}
void modify(ll ql, ll qr, ll l, ll r, ll rt, ll val){
	if (lazy[rt]!=0) push_down(l, r, rt);
	if (ql<=l&&qr>=r) return lazy[rt]+=val, seg[rt]+=val*(r-l+1), void();
	ll m=(l+r)/2;
	if (m>=qr) modify(ql, qr, l, m, rt<<1, val);
	else if (m<ql) modify(ql, qr, m+1, r, rt<<1|1, val);
	else modify(ql, qr, l, m, rt<<1, val), modify(ql, qr, m+1, r, rt<<1|1, val);
	seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
int main(){
	cin >> n;
	build(1, n, 1);
	cin >> q;
	for (ll i=0;i<q;i++){
		cin >> d1;
		if (d1==1) cin >> d1 >> d2 >> d3, modify(d1, d2, 1, n, 1, d3);
 	    else cin >> d2 >> d3, cout << query(d2, d3, 1, n, 1) << "\n";
	}
}
