#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long n, q, se, a, b, sum;
int main(){
	vector<int> v; 
	while (cin >> n >> q){
		v.clear();
		for (int i=1;i<=n;i++)
			cin >> se, v.push_back(se);
		sort (v.begin(), v.end());
		for (int i=0;i<q;i++){
			cin >> se, sum=0;
			auto it = upper_bound(v.begin(), v.end(), se);//iterator != int
			if(it == v.end()) a=v.size();
			else a = it-v.begin();
			cout << a%2 << "\n";
		}
	}
}
