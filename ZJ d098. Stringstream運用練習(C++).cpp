#include<bits/stdc++.h>
#include<sstream>
using namespace std;
string s, s1;
stringstream ss;
long long t, bo, ans;
int main(){
	while (getline(cin, s)){
		ss.clear();
		ss<<s;
		ans=0;
		while (ss>>s1){
			bo=0;
			for (int i=0;i<s1.size();i++)
				if (s1[i]<'0'||s1[i]>'9') bo=1;
			if (bo==0) ans+=stoi(s1);
		}
		cout << ans << "\n";
	}
} 
