#include<iostream>
#include<cstring>
using namespace std;
int n, q, d1, d2;
int dp[20][500005], a[500005];
void build(){
	for (int i=0;i<n;i++) dp[0][i]=i;
	for (int i=1;(1<<i)<=n;++i)
		for (int j=0;j+(1<<i)<=n;++j){
			int &L=dp[i-1][j], &R=dp[i-1][j+(1<<(i-1))];
			dp[i][j]=(a[L]>=a[R]?L:R);
		}
}
int query(int l, int r){
	int p=r-l+1, now=1;
	for(int i=0;(1<<i)<=p;i++) now=i;	//p=__lg(r-l+1);
//	cout << now << " ";
	p=now;
	return max(a[dp[p][l]], a[dp[p][r-(1<<p)+1]]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin >> n){
		memset(a,0,sizeof(a));	
		for (int i=0;i<n;i++) cin >> a[i];
		build();
		cin >> q;
		for (int i=0;i<q;i++){
			cin >> d1 >> d2;
			int l, r;
			d1--, d2--;
			if (d1>=d2) l=d2, r=d1;
			else l=d1, r=d2;
			cout << query(l, r) << "\n";
		}
	}
} 
