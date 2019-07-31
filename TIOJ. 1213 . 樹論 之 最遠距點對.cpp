#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define S second
#define F first
using namespace std;
typedef pair<int, int> pii;
vector<pii>v[100005];
int n, d1, d2, d3, r1, r2;
int bo[100005];
void dfs(int x, int R){
	bo[x]=1, r1=max(r1, R);
	if (r1==R) r2=x;
	for (auto i:v[x]) if (bo[i.F]==0) dfs(i.F, R+i.S);
	
}
int main(){
	while (cin >> n, n){
		r1=0, memset(bo,0,sizeof(bo));
		for (int i=0;i<100005;i++) v[i].clear();
		for (int i=1;i<n;i++) cin >> d1 >> d2 >> d3, v[d1].push_back({d2, d3}), v[d2].push_back({d1, d3});
		dfs(1, 0);
		r1=0, memset(bo,0,sizeof(bo));
		dfs(r2, 0);
		cout << r1 << "\n";
	}
} 
