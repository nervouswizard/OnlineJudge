#include<iostream>
#include <queue>

using namespace std;
int used[1000000];

struct Ta{
	int idx,data;
	Ta(int _idx,int _data){
		idx = _idx, data = _data;   //idx=top   data=a
	}
	bool operator<(const Ta &x)const{
		return data > x.data;
	}
};//less

struct Tb{
	int idx,data;
	Tb(int _idx,int _data){
		idx=_idx, data=_data;  
	}
	bool operator<(const Tb &x)const{
		return data < x.data;
	}
};//greater

int main(){
	ios::sync_with_stdio(false),cin.tie(false),cout.tie(false);
	int a,top=0;
	priority_queue<Ta> pq;     //greater
	priority_queue<Tb> pq2;    //less
	while (cin >> a, a){
		if (a == -2) {
			while(pq2.size() && used[pq2.top().idx]==-1)  pq2.pop();
			if(pq2.empty())continue;
			Tb T=pq2.top(); pq2.pop();
			used[T.idx] = -1;
			cout << T.data <<' ';
		}//big
		else if (a == -1){
			while(pq.size() && used[pq.top().idx]==-1)	pq.pop();
			if(pq.empty())continue;
			Ta T=pq.top(); pq.pop();
			used[T.idx] = -1;
			cout << T.data <<' ';
		}//smal
		else {
			pq.push(Ta(top,a));
			pq2.push(Tb(top,a)), ++top;
		}
	}
}
