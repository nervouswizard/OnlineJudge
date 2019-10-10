#include<bits/stdc++.h>
#define jizz ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) x&-x
#define F first 
#define S second 
#define pb push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9;
const int MAXN=5000;
stack<int> s1;
stack<int> s2;
void solve(int N, int order[])
{
	int j=0, x;
	for (int i=1;i<=N;i++)
	{
		x=order[j];
		if (x==i)
		{
			push_train();
			move_station_1_to_2();
			pop_train();
			j++;
		}
		else 
		{
			push_train();
			s1.push(i);
		}
	}
	for (;j<N;j++)
	{
		x=order[j];
		while (s1.size())
		{
			if (s1.top()==x)
			{
				s1.pop();
				move_station_1_to_2();
				pop_train();
				break;
			}
			else 
			{
				s2.push(s1.top());
				s1.pop();
				move_station_1_to_2();
			}
		}
		while (s2.size())
		{
			if (s2.top()==x)
			{
				s2.pop();
				pop_train();
				break;
			}
			else 
			{
				s1.push(s2.top());
				s2.pop();
				move_station_2_to_1();
			}
		}
	}
} 
