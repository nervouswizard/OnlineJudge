#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, j[100010];
	double d, sum;
	while(cin >> n, n){
		for (int i=0;i<n;i++) cin >> j[i];
		sort(j, j+n), sum=0;
		for (int i=1;i<n-1;i++)	sum+=j[i];
		cout << fixed << setprecision(2)<< sum/(n-2) << "\n";
	}
} 
