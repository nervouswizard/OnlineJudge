#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
int n, d1, d2;
vector<int> v;
vector<int> c;
int dp[105][105];
int main(){
	while (cin >> n){
		v.clear();c.clear();
		for (int i=0;i<105;i++) memset(dp[i],0,sizeof(dp[i]));
		v.push_back(0);
		c.push_back(0);
		for (int i=1;i<=n;i++){
			cin >> d1 >> d2;
			v.push_back(d1);
			c.push_back(d2);
		}
		for (int i=0;i<=100;i++) dp[0][i]=0;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=100;j++){
				int tmp;
				if (j-v[i]>=0) tmp=dp[i-1][j-v[i]]+c[i];
				else tmp=0;
				dp[i][j]=max(tmp, dp[i-1][j]);
			}
		}
		cout << dp[n][100] << "\n";
	}
} 
