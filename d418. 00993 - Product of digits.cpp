#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){ 
	int n, data, j, o, i;
	cin>>n;
	while(n--){ 
		cin >> data, j=0;
		if (data != 1){ 
			for (i=9;i>1;i--){ 
				if ((data%i)==0)
					a[j]=i, data=data/i, i++, j++;
			} 
			if (data!=1) cout << -1 <<'\n';
			else{ 
				for(j--;j>=0;j--) cout << a[j];
				cout << '\n';
			} 
		} 
		else cout << 1 << "\n";
	} 
} 
