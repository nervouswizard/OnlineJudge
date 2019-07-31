#include <iostream>

using namespace std;

long long a[101];

long long dp(long long i){
	if(i==0||i==1) return 1;
	if (a[i] != 0) return a[i];
	return a[i] = dp(i-1)+dp(i-2); 
}

int main(){
	a[0] = a[1] = 1;
	long long data;
	while(cin >> data){
		cout << dp(data) << "\n";
	}
} 
