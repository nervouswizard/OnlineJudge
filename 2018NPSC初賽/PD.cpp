#include<bits/stdc++.h>

using namespace std;
struct T {
	int f, s;   	 
}tree[5005];
Sort(T a,T b){
	return a.s<b.s;
}
SSort(T a,T b){
	return a.f>b.f;
}
int main(){
	int n, k, sum, ans = -1, fuck = -1;
	cin >> n >> k;
	for (int i=0;i<n;i++)	cin >> tree[i].f, sum += tree[i].f;
	for (int i=0;i<n;i++)	cin >> tree[i].s;
	sort(tree, tree+n, SSort);
	int h = tree[0].f;
	if (sum>k){
		sort(tree, tree+n, Sort);
		for (int i=0;i<n;i++) if (tree[i].f == k) fuck = 0;
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (tree[i].f+tree[j].f == k) fuck = 0;
		if (fuck != 0){
			for (int i=0;i<n;i++){
				if (tree[i].f+h) ans = tree[i].s; 
				break;
			}
			cout << ans;
		}
		else cout << 0;
	}
	else cout << "-1";
}
