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
const int MAXN=1e6;
struct node
{
	int d;
	node *r=nullptr, *l=nullptr;
};
int n, m, d1, d2;
node B[105], E[105], a[MAXN+5];
string s;
int main()
{
	cin >> n >> m;
	for (int i=0;i<=MAXN;i++)
		a[i].d=i;
	for (int i=0;i<=100;i++)
		B[i].r=&E[i], E[i].l=&B[i];
	while (m--)
	{
		cin >> s;
		if (s[0]=='A')
		{
			cin >> d1 >> d2;
			a[d2].r=&E[d1];
			a[d2].l=E[d1].l;
			if (E[d1].l!=nullptr)
				E[d1].l->r=&a[d2];
			E[d1].l=&a[d2];
		}
		else if (s[0]=='L')
		{
			cin >> d1;
			if (B[d1].r==&E[d1])
				cout << "queue "<< d1 <<" is empty!\n";
			else 
			{
				B[d1].r->r->l=&B[d1];
				B[d1].r=B[d1].r->r;
			}
		}
		else 
		{
			cin >> d1 >> d2;
			E[d2].l->r=B[d1].r;
			B[d1].r->l=E[d2].l;
			E[d2].l=E[d1].l;
			E[d1].l->r=&E[d2];
			B[d1].r=&E[d1];
			E[d1].l=&B[d1];
		}
	}
	node x;
		for (int i=1;i<=n;i++)
		{
			cout << "queue " << i << ":";
			if (B[i].r==&E[i])
				cout << " empty\n";
			else 
			{
				x=B[i];
				while (x.r!=&E[i])
				{
					x=*x.r;
					cout << " " << x.d;
				}
				cout << "\n";
			}
		}
}
