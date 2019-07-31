#include<bits/stdc++.h>
using namespace std;
struct srt{
	int c, e;
	bool operator<(const srt &x)const{
		if(e!=x.e) return e>x.e;
		else if(c>x.c) return e<x.e;
		else return e>x.e;
 	}
}di[1001];
int main(){
	int n, sum, a[1001];
	while(cin >> n){
		for(int i=0;i<n;i++)	cin >> di[i].c >> di[i].e;
		sort(di, di+n), sum=0;
		sum=di[0].c+di[0].e, a[0]=di[0].c;
		for(int i=1;i<n;i++){
			if (di[i].c+di[i].e+a[i-1]>sum)
				sum=di[i].c+di[i].e+a[i-1];
			a[i]=a[i-1]+di[i].c;
		}
		cout << sum << "\n";
	} 
}

