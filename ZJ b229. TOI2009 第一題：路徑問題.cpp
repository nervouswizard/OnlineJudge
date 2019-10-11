#include<iostream>
#include<string>
using namespace std;

int main(){
	string u, f, l, sum;
	unsigned long long data, n;
	unsigned long long fu[55], fr[55], fl[55];
	fu[1]=1, fr[1]=1, fl[1]=1;
	for(int i=1;i<51;i++){
		fu[i+1]=fu[i]+fr[i]+fl[i];
		fr[i+1]=fu[i]+fr[i];
		fl[i+1]=fu[i]+fl[i];
	}
	while(cin >> data){
		cout << fu[data]+fr[data]+fl[data] <<'\n';
	}	
} 

