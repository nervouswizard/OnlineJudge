#include<iostream>
#include<cstring>
using namespace std;
int u, n, k, no1, have, nohave, Bool, no2;
string s;
int fool(char data){
	if (data=='a') return'b';
	else if (data=='b') return'd';
	else if (data=='c') return'f';
	else if (data=='d') return'e'; 
	else if (data=='e') return'o';
	else if (data=='f') return'h';
	else if (data=='h') return'i';
	else if (data=='i') return'j';
	else if (data=='j') return'k';
	else if (data=='k') return'l';
	else if (data=='l') return'm';
	else if (data=='m') return'n';
	else if (data=='n') return'r';
	else if (data=='o') return'p';
	else if (data=='p') return'q';
	else if (data=='r') return's';
	else if (data=='s') return't';
	else if (data=='t') return'u';
	else if (data=='u') return'v';
	else if (data=='v') return'w';
	else if (data=='w') return'x';
	else if (data=='x') return'y';
	else if (data=='y') return'z';
}

int main(){
	cin >> u;
	while (u--){
		have=0,nohave=0;
		cin >> n >> k >> s;
		for (no1=n-1;no1>=0;--no1) {
			if (s[no1]!='q'&&s[no1]!='z') break;
			else if (s[no1]=='q') ++have;
		}
		if (!have) s[no1]=fool(s[no1]);
		else{
			if (s[no1]=='a'||s[no1]=='b'||s[no1]=='d'||s[no1]=='e'||s[no1]=='o'||s[no1]=='p') ++have;
			s[no1] = (char)(int)++s[no1]; if (s[no1]=='g') s[no1] = (char)(int)++s[no1];
			if (s[no1]=='a'||s[no1]=='b'||s[no1]=='d'||s[no1]=='e'||s[no1]=='o'||s[no1]=='p'||s[no1]=='q') --have;
			for(no2=no1+1;no2<n;no2++){
				if (have) s[no2] = 'a', --have;
				else s[no2] = 'c';
			}
		}
		if (no1==-1) cout << "-1\n";
		else cout << s << "\n";
	}
}
