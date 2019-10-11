#include <iostream>
#include <algorithm>

using namespace std;
int a[1000001];
int main(){
	int n;
	    cin >> n; 
		for (int i = 0; i<n; i++)
			cin >> a[i];
		sort(a, a+n);
		for (int i = 0; i<n; i++)
			cout << a[i] << " \n"[i==n-1];   //如果 i == n-1 輸出"\n" 否則輸出" "  
} 
