#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int ans=0, fuck=0, gg, kk;
	string s;
	while(getline(cin, s)){
		ans=0, fuck=0, gg=0, kk=0;
		for (int i=0;i+1<s.size();i++) {
			if (ans==0&&s[i]=='A'&&s[i+1]=='B') ans=1, i++;
			else if (ans==1&&s[i]=='B'&&s[i+1]=='A') fuck=1, i++;
		}for (int i=0;i+1<s.size();i++) {
			if (gg==0&&s[i]=='B'&&s[i+1]=='A') gg=1, i++;
			else if (gg==1&&s[i]=='A'&&s[i+1]=='B') kk=1, i++;
		}
		if ((ans==1&&fuck==1)||(gg==1&&kk==1)) cout << "YES\n";
		else cout << "NO\n";
	}
} 
