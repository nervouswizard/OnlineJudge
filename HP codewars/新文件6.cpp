#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,a[256],i,j,mx=0,op,ed,me;
	bool fl;
	cin>>n;
	for(i=0;i<n;++i)cin>>a[i];
	for(i=0;i<n;){
		fl=0;
		op=i;
		while(true){
			if(a[i]>a[i+1])++i,fl=1;
			else break;
		}
		me=i;
		while(true&&fl){
			if(a[i]<a[i+1])++i;
			else break;
		}
		ed=i;
		if(fl)me=max(min(a[op]-a[me],a[me]-a[ed]),me);
		else ++i;
	}
	cout<<me;
}
