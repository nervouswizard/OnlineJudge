#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n, dp[1005][1005], a[1005], Ans, sum;
int main(){
	cin >> n;
	for (long long i=0;i<n;i++)
		for (long long j=0;j<n;j++)
			cin >> dp[i][j];
	for (long long i=0;i<n;i++)
	{
		memset(a,0,sizeof(a));
		for (long long j=i;j<n;j++)
		{
			sum=0;
			for (long long k=0;k<n;k++)
			{
				a[k]+=dp[j][k];
				if (sum>0) sum+=a[k];
				else sum=a[k];
				if (sum>Ans) Ans=sum;
			}
		}
	}
	cout << Ans << "\n";
}
