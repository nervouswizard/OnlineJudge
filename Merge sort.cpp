#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, a;
vector<int> v;
void Mergesort(int f, int s){
	if(f==s) return;
	int mid = f+s>>1;
	Mergesort(f, mid);
	Mergesort(mid+1, s);
	queue<int> q;
	int n1 = f, n2 = mid+1;
	while(n1<=mid&&n2<=s){
		if (v[n1]<=v[n2]) q.push(v[n1]), ++n1;
		else q.push(v[n2]), ++n2;
	}
	while(n1<=mid) q.push(v[n1]), ++n1;
	while(n2<=s) q.push(v[n2]), ++n2;
	for (int i=f; i<=s; i++){
			int Top=q.front();
			q.pop();
			v[i]=Top;
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (cin >> n){
		v.resize(n);
		for(int i=0;i<n;i++) cin >> v[i];
		Mergesort(0, v.size()-1);
		for(int i=0;i<n;i++) cout << v[i]<<' ';
		cout << '\n';
	}
}
