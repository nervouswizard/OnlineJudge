#include<iostream> //3
#include <cstring>

using namespace std;
#define intz(a) (a - '0')
int main(){
	string s;
	int sum ,i ,j ,count;
	bool error;
	while(cin >> s)
	{
		for(i = 0;i != (1 << (s.size() - 1));i++)
		{
			count = error = 0;
			
			sum = intz(s[0]);
			for(j = 1;j != s.size();j++)
			{
				cout << "sum" << sum << " i" << i << endl;
				if(i >> (j - 1) & 1) sum *= 10 ,sum += intz(s[j]);
				else
				{
					if(1 <= sum && sum <= 26)
					{
						error = true;
						break;
					}
					else
						sum = intz(s[j]);
				}
			}
			if(!error) count += 1;
		}
		cout << count << endl;
	}
}
