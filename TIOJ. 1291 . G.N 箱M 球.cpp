#include<iostream>

using namespace std;

long long dp[201][201];

int main(){
	long long n, m;
	dp[0][0]=1;
	for (int i = 1;i<=200;i++)
		for (int j=1;j<=200;j++)
			dp[i][j]=(dp[i][j-1]*i+dp[i-1][j-1])%1000000;
	for (int i = 1;i<=200;i++)
		for (int j=1;j<=200;j++)
			dp[i][j]=(dp[i][j]+dp[i-1][j])%1000000;
	while(cin >> n >> m, n+m!=0) cout << dp[n][m] << "\n"; 
}
