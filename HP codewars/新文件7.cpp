#include <iostream>

using namespace std;

int data[1000000];

int main()
{
	int n ,sum ,tmp ,old;
	int i;
	while(cin >> n)
	{
		sum = 0;
		for(i = 1;i <= n;i++)
			cin >> data[i];
		for(i = 1;i <= n;i++)
		{
			if(data[i] == -1) continue;
			
			tmp = data[i]; data[i] = -1;
			while(tmp != i) {
				old = data[tmp];
				data[tmp] = -1;
				tmp = old;
			}
			sum += 1;
		}
		cout << n - sum << endl;
	}
}
