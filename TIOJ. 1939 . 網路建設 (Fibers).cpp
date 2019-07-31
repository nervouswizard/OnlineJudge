#include<iostream>
#define MOD 1000000009
using namespace std;
typedef long long LL;
int main(){
	int n;
	LL dp[101], f[101];
	dp[1] = 1, f[1] = 1, f[0] = 0;
	for (int i=2;i<=100;++i){
		dp[i]=(dp[i-1]*3+1+f[i-2]*2)%MOD;
		f[i]=(f[i-1]+dp[i])%MOD;
	}
	cin >> n;
	while (n--){
		int i;
		cin >> i;
		cout << dp[i] << "\n"; 
	}
} 
