#include<iostream>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
int n, nn, data, t;
map<int,int> m;
queue<int>team[1005];
queue<int>all;
string s;
int vis[1005];
void Enqueue(int x){
	if (m[x]==0) team[0].push(x), all.push(0);
	else {
		team[m[x]].push(x);
		if (vis[m[x]]==0) vis[m[x]]=1, all.push(m[x]);
	}
}
void Dequeue(){
	int x=all.front();
	if (x==0){
		cout << team[0].front() << "\n", team[0].pop(), all.pop();
	} 
	else {
		cout << team[x].front() << "\n", team[x].pop();
		if (team[x].empty()) vis[x]=0, all.pop();
	}
}
int main(){
	while (cin >> n){
		m.clear();
		for(int i=0;i<1005;i++)
			while (team[i].size()) team[i].pop();
		while (all.size()) all.pop();
		memset(vis,0,sizeof(vis));
		cout << "Line #" << ++t << "\n";
		for (int i=1;i<=n;i++){
			cin >> nn;
			for (int j=0;j<nn;j++)
				cin >> data, m[data]=i;
		}
		while (cin >> s, s!="STOP"){
			if (s=="ENQUEUE") cin >> data, Enqueue(data);
			else if (s=="DEQUEUE") Dequeue();
		}
	}
}
