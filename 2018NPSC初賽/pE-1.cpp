#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, j;
	double sum =0;
	long long x[2002], y[2002];
	cin >> n;
	j = n*(n - 1) / 2;
	for (int i=0;i<n;i++){
		cin >> x[i] >> y[i];
		for (int k=0;k<i;k++){
			sum += (double)((sqrt((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]))/j));
		}
	}
	cout << fixed << setprecision(18) << sum*3;
}
