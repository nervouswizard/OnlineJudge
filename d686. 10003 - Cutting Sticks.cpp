#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
int L, dp[55][55], a[55], n;
int cut(int l, int r){
	if(dp[l][r]>-1) return dp[l][r];
	int ans=INF;
	for (int i=l+1;i<r;++i)
		ans=min(ans, cut(l, i)+cut(i, r)+a[r]-a[l]);
	return dp[l][r]=ans;
}
int  main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while (cin >> L, L){
		memset(dp,-1,sizeof(dp));
		cin >> n;
		a[0]=0, a[++n]=L;
		for (int i=0;i<=n;++i) {
			if (i!=0&&i!=n) cin >> a[i];
			dp[i][i+1]=0;	
		} 
		cout << "The minimum cutting is " << cut(0, n) << ".\n";
	}
} 
