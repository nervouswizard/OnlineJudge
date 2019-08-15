#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int inf=1e5;
const int mod=1e9+7;
int q, n, d, mtx, utx, mty, uty;
int a[100005][10];
int main()
{
	cin >> q;
	while (q--)
	{
		mtx=mty=-inf;
		utx=uty=inf;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<6;j++)
			{
				a[i][j]=0;
			}
		}
		cin >> n;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<6;j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i=0;i<n;i++)
		{
			if (a[i][2]==1&&a[i][4]==0)
				utx=min(utx, a[i][0]);
			if (a[i][4]==1&&a[i][2]==0)
				mtx=max(mtx, a[i][0]);
			if (a[i][4]==0&&a[i][2]==0)
				utx=min(utx, a[i][0]), mtx=max(mtx, a[i][0]);
			if (a[i][3]==1&&a[i][5]==0)
				mty=max(mty, a[i][1]);
			if (a[i][5]==1&&a[i][3]==0)
				uty=min(uty, a[i][1]);
			if (a[i][3]==0&&a[i][5]==0)
				mty=max(mty, a[i][1]), uty=min(uty, a[i][1]);
			
		}
		cout << mtx << " " << utx << " " << mty << " " << uty << "\n";
//		if (mtx<=utx&&mty<=uty) cout << "1 " << mtx << " " << mty << "\n";
//		else cout << 0 << "\n";
	}
}
