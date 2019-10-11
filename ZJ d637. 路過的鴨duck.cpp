#include <bits/stdc++.h>

using namespace std;

int duck[10005][105]; //nÁû, Åé¿na, ¹¡¨¬·Pduck[n][a]; 
int w[10005];

int duckDP(int i, int j, int b){
	if(j-w[i]<0) return duck[i][j] = duck[i-1][j]; 
	return duck[i][j] = max (duck[i-1][j], duck[i-1][j-w[i]] + b);
}

int main(){
	int i, j, n, nn = 0, a=100, b;
	cin >> n >> w[0] >> b;
	for(i = 1;i <= a; i++) duck[0][i] = -1e9;
	duck[0][w[0]] = b;
	for (i = 1; i < n; i++){
		cin >> w[i] >> b;
		for(j = 1; j <= a; j++) duckDP(i,j,b);
	}
	for (i = 0; i <= a; i++) nn = max(nn, duck[n-1][i]);
	cout << nn << "\n";
} 
