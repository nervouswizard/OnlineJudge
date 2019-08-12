#include<bits/stdc++.h>
using namespace std;
long long n, d, Max, sum;
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> d;
		sum+=d;
		Max=max(Max, d);
	}
	if (sum%2==1||Max*2>sum) cout << "NO";
	else cout << "YES";
} 
