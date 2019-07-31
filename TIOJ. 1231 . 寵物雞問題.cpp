#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct Ta{
	int idx,data;
	Ta(int _data, int _idx){
		data=_data, idx=_idx;
	}
	bool operator<(const Ta &x)const{
		return data<x.data;
	}
};//¤j¨ì¤p 

int main(){
	int n, a, b, c, sum=0;
	priority_queue<Ta> pq;
	cin >> n;
	while (n--){
		cin >> a >> b;
		pq.push(Ta(a,b));
	}
	cin >> c;
	for (int i=c;i>=1;i--){
		while (pq.top().idx > i || pq.top().idx <= c-i) pq.pop();
		if (pq.empty()) sum-=1;
		else sum += pq.top().data, pq.pop();
	}
	cout << sum << "\n";
} 
