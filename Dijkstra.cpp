#include<bits/stdc++.h>
#define INF 2147483647
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii; //s到點的權重, 某點 
int dis[10000000]; //dis[i] = i點的 Dijkstra 
vector<pii> child[100000]; //child[1] = 2(1到2的權重),2(1到2)
void Dijkstra(int s){ //s-start t-end
	priority_queue<pii, vector<pii>, greater<pii> > pq; // pq.F(起點到pq.S點的權重) pq.S(某個點) 
	for(int i=1;i<=n;++i) dis[i]=INF;
	pq.push(MP(0,s)),dis[s]=0;
	while(!pq.empty()){
		auto pqt=pq.top();
		pq.pop();
		if (dis[pqt.S]!=pqt.F) continue; //dis[pq.S] != pq.F
		for(auto i:child[pqt.S])
			if (pqt.F+i.F<dis[i.S])
				dis[i.S]=pqt.F+i.F, pq.push(MP(pqt.F+i.F, i.S));
	}
}
  
int main(){

} 
