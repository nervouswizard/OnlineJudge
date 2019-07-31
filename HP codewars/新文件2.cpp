#include <iostream>  //1

using namespace std;

int main() {
	long long n ,m ,sum ,data[1002];
	long long i ,tmp;
	while(cin >> n)
	{
		for(i = 0;i != n;i++) cin >> data[i];
		
		cin >> m;
		for(sum = i = 0;i != m;i++) cin >> tmp ,sum += tmp;
		
		sum = (sum > 0 ? sum % n : -((-sum) % n));
		for(i = 0;i != n;i++)
			cout << data[((i + n) - sum) % n] << " ";
		cout << endl;
	}
}
