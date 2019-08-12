#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int inf=1e9+7;
int q, n, k, cnt, Min;
string s;
int main()
{
	string rgb="RGB";
	cin >> q;
	while (q--)
	{
		Min=inf;
		cin >> n >> k >> s;
		for (int i=0;i<3;i++)
		{
			cnt=0;
			for (int j=0;j<k;j++)
			{
				if (s[j]!=rgb[(i+j)%3])
					cnt++;
			}
			Min=min(Min, cnt);
			for (int j=k;j<n;j++)
			{
				if (s[j]!=rgb[(i+j)%3])
					cnt++;
				if (s[j-k]!=rgb[(i+j-k)%3])
					cnt--;
				Min=min(Min, cnt);
			}
		}
		cout << Min << "\n";
	}
}
