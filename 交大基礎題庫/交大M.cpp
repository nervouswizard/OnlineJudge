#include<iostream>
using namespace std;
int main(){
	long long a;
	cin >> a;
	if (a%2==0) cout << a/2 << "\n";
	else cout << 0-(a+1)/2 << "\n";
}
