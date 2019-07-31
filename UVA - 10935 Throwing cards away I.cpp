#include <bits/stdc++.h>

using namespace std;

int q[1000000] = {}, l, r;

inline void push (int data){
	q[++r] = data;
}

inline void pop(){
	if (r<l)return;
	++l;
}

inline int top(){
	return q[l];
}

int main(){
	int n, i;
	while (cin >> n, n){
		if (n == 1){
			cout << "Discarded cards:\nRemaining card: 1\n";
			continue;
		}
		l = 0, r = -1;
		for (i = 1; i <= n; i++){
			push(i);
		}
		cout << "Discarded cards: ";
		while (r-l!=1){
			cout << top() << ", ";
			pop();
			push(top()), pop();
		}
		cout << top() << "\n" << "Remaining card: "<< q[r] << "\n";
	}
}
