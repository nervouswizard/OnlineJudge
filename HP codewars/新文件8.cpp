#include <iostream>
#include <algorithm>

using namespace std;
struct p{
	int x, y;
};

bool cmp(p a,p b)
{
	if(a.x == b.x)
		return (a.y < b.y);
	return (a.x < b.x);
}

int main(){
	p data[4];
	int i;
	int code[4];
	bool able;
	while(cin >> data[0].x >> data[0].y)
	{
		for(i = 1;i != 4;i++) cin >> data[i].x >> data[i].y;
		sort(data ,data + 4 ,cmp);
		
	//	for(i = 0;i != 4;i++) cout << data[i].x << " " << data[i].y << endl;
		if(data[0].x - data[2].x == data[0].y - data[1].y && data[0].y - data[1].y != 0
			&& data[0].x == data[1].x && data[2].x == data[3].x
			&& data[0].y == data[2].y && data[1].y == data[3].y)
		{
			cout << "True" << endl;
			cout << data[1].x << " " << data[1].y << endl;
			cout << data[0].x << " " << data[0].y << endl;
			cout << data[2].x << " " << data[2].y << endl;
			cout << data[3].x << " " << data[3].y << endl;
		}
		else
			cout << "False" << endl;
	}
}
