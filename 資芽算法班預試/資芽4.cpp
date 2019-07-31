#include<bits/stdc++.h>
using namespace std;
string s, ss;
int n, ans, maa[100];
vector<string> v;
int cmp(string a, string b){
	if (a[1]==b[1]) return a[0]<b[0];
	return a[1]<b[1];
}
void def(string a){
	if (a[0]=='E') maa[31]++;
	else if (a[0]=='S') maa[32]++;
	else if (a[0]=='W'&&a[1]=='W') maa[33]++;
	else if (a[0]=='N') maa[34]++;
	else if (a[0]=='R') maa[35]++;
	else if (a[0]=='G') maa[36]++;
	else if (a[0]=='W') maa[37]++;
	else if (a[1]=='W') maa[a[0]-48]++;	//1~9
	else if (a[1]=='B') maa[a[0]+10-48]++;	//11~19
	else if (a[1]=='T') maa[a[0]+20-48]++; //21~29
}
int main(){
	cin >> n;
	while (n--){
		cin >> s;
		v.clear();
		for (int i=0;i<17;i++) cin >> ss, v.push_back(ss);
		sort(v.begin(), v.end(), cmp);
		for (int i=0;i<16;i++){
			if (v[i]==v[i+1]){
				memset(maa,0,sizeof maa);
				ans=0;
				for (int j=0;j<17;j++) if (j!=i&&j!=i+1) ss=v[j],def(ss);
				for (int j=1;j<10;j++){
					if (maa[j]>=3) maa[j]-=3;
					if (j<=7&&maa[j]>0) maa[j+1]-=maa[j], maa[j+2]-=maa[j], maa[j]=0;
				}
				for (int j=11;j<20;j++){
					if (maa[j]>=3) maa[j]-=3;
					if (j<=17&&maa[j]>0) maa[j+1]-=maa[j], maa[j+2]-=maa[j], maa[j]=0;
				}
				for (int j=21;j<30;j++){
					if (maa[j]>=3) maa[j]-=3;
					if (j<=27&&maa[j]>0) maa[j+1]-=maa[j], maa[j+2]-=maa[j], maa[j]=0;
				}
				for (int j=31;j<=37;j++) if (maa[j]>=3) maa[j]-=3;
				for	(int j=1;j<=37;j++) if (maa[j]!=0) ans=1;
				if (ans==0) break;
			//	for (int j=1;j<=37;j++) cout << maa[j] << " ";
			//	cout << "\n";
			}
		}
		if (ans==0) cout << s << " can yell out Mahjong!\n";
		else cout << "Nothing happened.\n";
	}
} 
