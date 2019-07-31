#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define F first 
#define S second 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll n, dp[105][105];
int main(){
	while (cin >> n){
		memset(dp,0,sizeof(dp));
		for (ll i=1;i<=n;i++) cin >> dp[i][i];
		for(ll j=2;j<=n;j++)
            for(ll i=j-1;i>=1;i--)
                for(ll k=i;k<j;k++)
                    dp[i][j]=max(dp[i][j],((j-i+1)&1?dp[i][k]*dp[k+1][j]:dp[i][k]+dp[k+1][j]));    
    	cout << dp[1][n] << "\n";
	}	
}
