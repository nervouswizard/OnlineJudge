#include<iostream>
#include<string>
#include<algorithm>
#define INF 1000000000
using namespace std;
int dp[1001][1001], a[1001];
int main (){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int nk, fi=0, k;
		cin >> nk, fi=0;
		for (int i=1;i<=nk;i++) cin >> a[i];
		dp[0][0]=-INF;
		for (int i=1;i<=nk;i++) dp[0][i]=INF;
		for (int n=1;n<=nk;n++){
			for (int i=1;i<=nk;i++){
				if (a[n]>dp[n-1][i-1])
					dp[n][i]=min(dp[n-1][i], a[n]);
				else dp[n][i]=dp[n-1][i];
			}
		}
		for (int i=1;i<=nk;i++) if (dp[nk][i] != INF) fi++;
		cout << fi << "\n";
	
} 
