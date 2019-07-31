#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long n, a, flag, kk;
vector<long long> v;
void Mergesort(long long f, long long s){
	if(f==s) return;
	long long mid = f+s>>1;
	Mergesort(f, mid);
	Mergesort(mid+1, s);
	queue<long long> q;
	long long n1 = f, n2 = mid+1;
	while(n1<=mid&&n2<=s){
		if (v[n1]<=v[n2]) q.push(v[n1]), ++n1;
		else q.push(v[n2]), ++n2, flag+=mid-n1+1;
	}
	while(n1<=mid) q.push(v[n1]), ++n1;	//n2 = s+1
	while(n2<=s) q.push(v[n2]), ++n2;	//n1 = mid+1
	for (long long i=f; i<=s; i++){
			long long Top=q.front();
			q.pop();
			v[i]=Top;
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	kk = 1;
	while (cin >> n, n){
		v.resize(n), flag = 0;
		for(long long i=0;i<n;i++) cin >> v[i];
		Mergesort(0, v.size()-1);
		cout << "Case #" << kk << ": " << flag << '\n', ++kk;
	}
}
