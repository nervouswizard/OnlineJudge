#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct st{
	int a, b;
};
priority_queue <int> pq;
vector<st>v;
vector<int> v2;
vector<int> v3;
vector<st> v4;												//ºC 
int n, m, q, d1, d2, d3, boss[10005], ans;
int query(int x){
	if (boss[x]==x) return x;
	else return boss[x]=query(boss[x]); 
}
void Union(int a, int b){
	a=query(a), b=query(b);
	if (a==b) return;
	else boss[a]=b, ans--;
}
int main(){
	while(cin >> n >> m){
		ans=n;
		v.clear();
		v2.clear();
		v3.clear();
		for (int i=0;i<=n;++i) boss[i]=i;
		for (int i=0;i<m;++i){
			cin >> d1 >> d2;
			v.push_back(st{d1,d2});
			v4.push_back(st{d1,d2});						//ºC 
		}
		cin >> q;
		for (int i=0;i<q;++i){
			cin >> d3, d3--;
			pq.push(d3);
			v2.push_back(d3);
		}
		while(!pq.empty()){
			int Top=pq.top();
			pq.pop();
			v4[Top].a=0, v4[Top].b=0;
		}
		for (int i=0;i<m;++i){								//ºC 
			if (v4[i].a!=0) Union(v4[i].a, v4[i].b);		//ºC 
		}													//ºC 
		for (int i=q-1;i>=0;--i){
			v3.push_back(ans);
			Union(v[v2[i]].a, v[v2[i]].b);
		}
		for (int i=q-1;i>=0;--i) cout << v3[i] << "\n";
	}
} 
