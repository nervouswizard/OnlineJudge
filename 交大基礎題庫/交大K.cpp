#include<iostream>
using namespace std;
	long long n, m, a, x1, x2;
int main(){
	cin >> n >> m >> a;
	for (int i=1;1;i++) 	if (a*i>=n){ x1=i; break;}
	for (int i=1;1;i++)	if (a*i>=m){ x2=i; break;}
	cout << x1*x2 << "\n"; 
}
