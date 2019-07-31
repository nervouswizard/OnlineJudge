#include <iostream>
using namespace std;
int main() {
	int n,m,a[21],t=0,c,d,sum=0;
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	cin>>m;
	while(--m){
		cin>>c;
		sum+=c;
	}
	if(sum<0){
		sum*=-1;
		t=sum%n;
	}
	else t=sum%n;
	d=n;
	while(d--){
		if(t<n)cout<<a[t++]<<" ";
		else if(n==t)t=0;
	}
}
