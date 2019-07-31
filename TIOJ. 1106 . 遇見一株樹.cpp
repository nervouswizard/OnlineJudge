#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
string s;
queue <int> q;
int L, D, B, r1, r2;
char c;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while (cin >> s){
		while (!q.empty()) q.pop();
		L=0, D=1, r1=1, B=0;
		for (int i=0;i<s.size();i++){
			if (s[i]=='*') L++;
			if (s[i]=='(') r1++;
			D=max(D, r1);
			if (s[i]==')') r1=1;
		}
		q.push(9), r1=0, r2=0;
		if (s[0]=='('&&s[s.size()-1]==')'){
			for (int i=1;i<s.size()-1;i++){
				if (r1==r2&&s[i]=='*') B++;
				if (s[i]=='('){
					if (q.back()==9) B++;
					q.push(6), r1++;
				} 
				if (s[i]==')') q.push(9), r2++;
			}
		}
		cout << L << " " << D << " " << B << "\n";
	}
} 
