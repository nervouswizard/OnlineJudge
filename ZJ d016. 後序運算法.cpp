#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	stack<int> sta;
	string s1;
	stringstream ss, ss2;
	int i = -1, num, n, m;
	while (getline(cin, s1)){
		ss.clear();
		ss << s1;
		while (ss >> s1){
			if (s1[0] == '%'){
			    n = sta.top();
			    sta.pop();
			    m = sta.top();
			    sta.pop();
			    sta.push(m % n);
			}
			if (s1[0] == '+'){
			    n = sta.top();
			    sta.pop();
			    m = sta.top();
			    sta.pop();
			    sta.push(n + m);
			}
			if (s1[0] == '-'){
			    n = sta.top();
			    sta.pop();
			    m = sta.top();
			    sta.pop();
			    sta.push(m - n);
			}
			if (s1[0] == '*'){
			    n = sta.top();
			    sta.pop();
			    m = sta.top();
			    sta.pop();
			    sta.push(n * m);
			}
			if (s1[0] == '/'){
			    n = sta.top();
			    sta.pop();
			    m = sta.top();
			    sta.pop();
			    sta.push(m / n);
			}
			for (i = 0; i < s1.size(); i++) 
				if (s1[i] >= '0' && s1[i] <= '9')i = i;
			else break;
			if (i == s1.size()){
				ss2 << s1;
				ss2 >> num;
				sta.push(num);
				ss2.clear();
			}
		}
		cout << sta.top() << "\n";
	}
}
