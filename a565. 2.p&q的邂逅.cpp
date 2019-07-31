#include <bits/stdc++.h>
using namespace std;
int a, i, f, k;
string b;
int main(){
	ios::sync_with_stdio(false);
	cin >> a;
	while (a--)
	{
		f = 0, k = 0;
		cin >> b;
		for (i=0;i<b.size();i++)
		{
			if (b[i] =='p') k++;
			if (b[i] =='q'&&k>0)
				k--,f++;
		}
		cout << f <<"\n";
	}
}
