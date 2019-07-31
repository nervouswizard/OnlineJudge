#include<iostream>

using namespace std;
long long L[30][30];
int gcda[30][30];
int gcd(int y, int x){
	int ju[30][30];
	if (ju[y][x]==1) return gcda[y][x];
	ju[y][x]=1;
	return gcda[y][x]=(x?gcd(x,y%x):y);
}
int main(){
	int n, g;
    L[1][1]=1;
    for (int r=2;r<29;r++)	L[r][1]=r, L[r][r]=r; //[y][1], [y][y]
	    for (int y=4;y<29;y++){
    	for (int x=2;x<=((y+1)/2);x++){
    		L[y][x]=(L[y][x-1]*L[y-1][x-1])/gcd(L[y][x-1],L[y-1][x-1]);
    		L[y][(y-x)+1]=L[y][x];
		}
	}
	L[4][2]=(L[3][1]*L[4][1])/gcd(L[3][1],L[4][1]);
		cout << L[4][2];
}
