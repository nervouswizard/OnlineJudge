#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int t, n;
stack<int>s;

bool solve(int id){
	while(t<=n&&t<=id)	s.push(t++);
	if(s.top()==id)	return s.pop(),1;
	return 0;
}

int main(){
	int i, a;
	int flag;
	while(cin >> n, n){
		while(!s.empty())	s.pop();
		while(cin >> a, a){
			t=flag=1;
			if(solve(a)==0)	flag=0;
			for(int i=1;i<n;i++) cin>>a, if(solve(a)==0) flag=0;
			if(flag)	cout  << "Yes\n";
			else 	cout << "No\n";
		}
	} 
}


   
