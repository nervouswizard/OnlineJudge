#include<iostream>
#include<string>
#include<map>

using namespace std;
 
int main(){
	int n, t;
	string s;
	map<string, int>m;
	while (cin >> n){
		t = 1;
		m.clear();
		while (n--){
			cin >> s;
			if (m[s]) cout << "Old! " << m[s] << "\n";
			else cout << "New! " << t << "\n", m[s] = t++;
		}
	}
} 
