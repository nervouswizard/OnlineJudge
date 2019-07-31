#include<iostream>
#include <queue>

using namespace std;

struct Ta{
	int data;
	Ta(int _data){
		data = _data;   //idx=top   data=a
	}
	bool operator<(const Ta &x)const{
		return data > x.data;
	}
};//less

struct Tb{
	int data;
	Tb(int _data){
		data=_data;  
	}
	bool operator<(const Tb &x)const{
		return data < x.data;
	}
};//greater

int main(){
	priority_queue<Ta> pq;     //greater
	priority_queue<Tb> pq2;    //less
	int n, k, data;
	cin >> n;
	while (n--){
		cin >> k;
		while (k--){
			cin >> data;
			pq.push(Ta(data));
			pq2.push(Tb(data));
		}
		while (!pq.empty()) cout << pq.top().data << " ", pq.pop();
		while (!pq2.empty()) cout << pq2.top().data << " ", pq2.pop();
	}
}
