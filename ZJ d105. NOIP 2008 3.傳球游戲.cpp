#include<iostream>
#include<string.h>
using namespace std;
long long n, m, dp[35][35];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin >> n >> m){
		memset(dp,0,sizeof(dp));
		dp[1][n]=1, dp[1][2]=1;
		for (int i=2;i<=m;i++)
			for (int j=1;j<=n;j++){
				if (j==1) dp[i][j]=dp[i-1][n]+dp[i-1][j+1];
				else if (j==n) dp[i][j]=dp[i-1][j-1]+dp[i-1][1];
				else dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			}
		cout << dp[m][1] << "\n";
	}	
}
