#include<iostream>
#include<vector>
using namespace std;
struct T{
	int a, b;
};
bool cmp(int a, int b){
	return a>b;
}
vector<T> v;
vector<int> bboss;
int d1, d2, d3, d4, bo, t, E, G;
int boss[1000005];
int query(int x){
	if (boss[x]==x) return x;
	return boss[x]=query(boss[x]);
}
void Union(int a, int b){
	a=query(a), b=query(b);
	if (a==b) return;
	boss[b]=a, E++;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	while (cin >> d1 >> d2, t++, d1+d2!=-2){
		if (d1+d2){
			bboss.clear();
			v.clear();
			for (int i=1;i<=100000;i++) boss[i]=i;
			bo=0;
			G=1;
			E=0;
			bboss.push_back(d1);
			bboss.push_back(d2);
			v.push_back(T{d1, d2});
			while (cin >> d3 >> d4, d3+d4) v.push_back(T{d3, d4}), bboss.push_back(d3), bboss.push_back(d4), G++;
			for (int i=0;i<v.size();i++) Union(v[i].a, v[i].b);
			for (int i:bboss) query(i);
			int befo=boss[bboss[0]];
			for (int i:bboss){
				if (boss[i]!=befo) bo=1;
				befo=boss[i];
			}
			if (bo==1) cout << "Case "<<t<<" is not a tree.\n";
			else if (E!=G) cout << "Case "<<t<<" is not a tree.\n";
			else cout << "Case "<<t<<" is a tree.\n";
		}
		else cout << "Case "<<t<<" is a tree.\n";
	}
} 

