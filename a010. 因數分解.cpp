#include <iostream>
#include <cmath>

using namespace std;

int j[1000005] = {};
int main(){
	int n, k, p, g;
	while (cin>>n){
		k=n;
 		for (int i=2; i<=k; i++)	
		 	if (n%i==0) {
			 	j[i]++;
			 	n/=i;
			 	i--;
			 }
			g = 0;
		for (int i=2; i<=k; ++i){
			if (j[i]==1){
				if (g!=0) cout << " * ";
				cout<<i;
				j[i] = 0;
				g++;
			}
			else if (j[i]!=0){
				if (g!=0) cout << " * ";
			 	cout<<i<<"^"<<j[i];
				j[i]=0;
				g++;
			}
		}
		cout<<"\n";
	}
} 
