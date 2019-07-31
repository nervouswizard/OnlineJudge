#include<iostream>
#include<vector>
using namespace std;
vector<int> v[100005];
int n, q, d1, d2, d3, t;
int W[100005], ac[18][100005], in[100005], out[100005];
int check(int a, int b){
	if (in[a]<=in[b]&&out[a]>=out[b]) return 1;
	return 0;
}
int LCA(int a, int b){
	if (check(a, b)) return a;
	for (int i=17;i>=0;i--){
		if (!check(ac[i][a], b)) a=ac[i][a];
	}
	return ac[0][a];
}
void dfs(int a, int f, int c){
	in[a]=t++, ac[0][a]=f;
	for (auto i:v[a]){
		if (i!=f){
			dfs(i,a,c+1);
		}
	}
	W[a]=c, out[a]=t;
}
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i=1;i<n;i++) cin >> d1 >> d2, v[d1].push_back(d2), v[d2].push_back(d1);
	dfs(1,1,0);
	for (int i=1;i<18;i++)
		for (int j=1;j<=n;j++)
			ac[i][j]=ac[i-1][ac[i-1][j]];
	for (int i=0;i<q;i++){
		int have=0, lca=0, d33=0;
		cin >> d1 >> d2 >> d3;
		lca=LCA(d1,d2), d33=d3;
		if (d33>W[d1]+W[d2]-2*W[lca]) cout << "-1\n";
		else {
			for (int j=1;j<=d3;j++)
				d1=ac[0][d1];
			if (d3>=W[d1]-W[lca]){
				have=1;
				d3=d3-(W[d1]-W[lca]);
				d3=(W[d2]-W[lca])-d3;
				for (int j=1;j<=d3;j++)
					d2=ac[0][d2];
			}
			else if(have==1) cout << d2 << "\n"; 
			else cout << d1 << "\n";
		}
	}
}
