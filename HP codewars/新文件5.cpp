#include <map>
#include <iostream>
using namespace std;


/*
5
3 1 2 3
2 1 1
4 10 5 5 1
0
1 2
*/
map<int ,int> data;
int main()
{
	int n ,k ,sum;
	int tmp ,big ,small;
	sum = 0;
	for(cin >> n;n--;)
	{
		for(cin >> k;k--;) cin >> tmp ,data[tmp] += 1;
		while(data.size() >= 1)
		{
			small = (*data.lower_bound(0)).first;
			data[small] -= 1;
			if(data[small] == 0) data.erase(small);
			
			big = (*data.upper_bound((1LL << 31) - 1)).first;	
			data[big] -= 1;
			if(data[big] == 0) data.erase(big);
				
			sum += big - small;
			
			
			printf("%d %d %d\n" ,big ,small ,data.size());
			system("pause");
			
		}
	}
	cout << sum;
}
