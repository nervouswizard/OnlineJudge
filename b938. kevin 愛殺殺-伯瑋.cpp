#include<iostream>

using namespace std;

struct nodes{
	int a;                     //自身的ID 
	bool d;                    //判斷是否被殺掉了 
	nodes *r;                  //下一個的位置 
	nodes(int p){
		a=p,r=0,d=0;
	}
}*arr[1000100],*END;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n, m, p;
	END = new nodes(0);
	for(int i = 1; i <= 1000000; i++)
		arr[i] = new nodes(i);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		arr[i] -> r = arr[i+1];
	arr[n] -> r = END;
	while (m--){
		cin >> p;
		if(arr[p] -> d || arr[p] -> r==END)
			cout << "0u0 ...... ?\n";
		else{
			cout << arr[p]-> r -> a << '\n';
			arr[p] -> r -> d = 1;
			arr[p] -> r = arr[p] -> r -> r;
		}
	}
}
