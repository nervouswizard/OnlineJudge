#include<bits/stdc++.h>
#include "lib1338.h"
using namespace std;
vector<long long> dp[21];
vector<long long> min_dp[21];
void init(int N, long long c[]){
	for (int i=0;i<N;i++){
		min_dp[0].push_back(c[i]);
		dp[0].push_back(c[i]);
	}
	for (int i=1;(1<<i)<=N;i++)
		for (int j=0;j+(1<<i)<=N;j++){
			long long L=min_dp[i-1][j], R=min_dp[i-1][j+(1<<(i-1))];
			min_dp[i].push_back(min(L,R));
			L=dp[i-1][j], R=dp[i-1][j+(1<<(i-1))];
			long long GCD=__gcd(L,R);
			dp[i].push_back(GCD);
		}
}
int query(int L, int R){
	long long p=__lg(R-L);
	long long m=min(min_dp[p][L], min_dp[p][R-(1<<p)]);
	long long g=__gcd(dp[p][L], dp[p][R-(1<<p)]);
	return m==g;
}
