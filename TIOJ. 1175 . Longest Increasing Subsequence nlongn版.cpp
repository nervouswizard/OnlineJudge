#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2147483647
using namespace std;
int n, j, lb, a[1000001];
vector<int> v;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i], v.push_back(INF);
	v[0]=a[0], j=1;
	for (int i=1;i<n;i++){
		lb=lower_bound(v.begin(), v.end(), a[i])-v.begin();
		v[lb]=a[i];
		if(a[i]>v[j-1]) v[j]=a[i], j++;
	}	
	cout << j;
} 
