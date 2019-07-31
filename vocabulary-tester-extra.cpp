#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <map>
#include <windows.h>
using namespace std;

long long t, all = 0, penalty;

string file, user, wa, dom;

fstream f, p;

map<string, string> mp;

struct voc{
	string vo, m;
};

struct w_voc{
	long long i;
	string vo, m, ans;
};

vector<voc> v;
vector<w_voc> w;

inline string random(){
	string s[6] = {
	"笑你啦，連這都不會", 
	"你是不是廢物啊", 
	"你幹嘛來背單字，回家睡覺就好啦", 
	"再不背單字啊，是你自己把自己當掉的", 
	"英文不用讀了啦，回家種田去吧你", 
	"想被Kate踩嗎"
	};
	return s[(rand() << 15 | rand()) % 6];
}

inline void normal_output(){
	int i;
	system("cls");
	cout << user << "     " << t << " 題\n\n";
	if(w.size() == 0)
		cout << "All pass!!\n\n";
	else
		cout << "本次錯誤單字:\n\n"; 
	for(i = 0; i < w.size(); i++){
		cout << "輸入答案：";
		if(w[i].ans == "")
			cout << wa;
		else
			cout << w[i].ans;
		cout << "    " << w[i].vo << w[i].m << "\n";
	}
	cout << "\n" << "答對率：" << fixed << setprecision(1) << double(t - w.size()) / t * 100 << "%\n\n";
	all += w.size() * penalty * 1000;
	cout << "時間：" << setprecision(1) << all / 1000 << "secs(" << all / 60000 << "m" << all % 60000 / 1000 << "s)     平均每題時間：" << setprecision(2) << all / 1000. / t << "secs     罰時：" << penalty * w.size() << "secs\n\n";
}

inline void dom_output(){
	int i, j;
	for(i = 0; i < w.size(); i++){
		system("cls");
		cout << "第 " << w[i].i << " 題\n\n";
		cout << w[i].m << "\n\n";
		for(j = 0; j < w[i].ans.size(); j++){
			cout << w[i].ans[j];
			Sleep(200);
		}
		cout << "\n\n" << random() << "\n";
		system("timeout -t 5");
	}
}

void initializer(){
	int i;
	string tmp1, tmp2;
	getline(p, tmp1);
	getline(p, tmp1);
	getline(p, tmp1);
	for(i = 0; i < 5; i++){
		getline(p, tmp1, '=');
		getline(p, tmp2);
		mp[tmp1] = tmp2;
	}
	file = mp["file"];
	user = mp["user"];
	wa = mp["non-input message"];
	dom = mp["do-M mode"];
	penalty = atoll(string(mp["penalty"]).c_str());
}

void get_voc(){
	string s, s1, c;
	while(f >> s){
		if(s == "----------")
			return;
		f >> c;
		getline(f, s1);
		if(s.size() != 1)
			v.push_back(voc{s, "  " + c + s1});
	}
}

void get_phr(){
	string s, s1;
	getline(f, s);
	while(getline(f, s, '\t'), getline(f, s1)){
		if(s.size() != 1)
			v.push_back(voc{s, "  phr " + s1});
	}
}

int main() {
	srand(time(NULL));
	long long i, r, j;
	clock_t op;
	string s, pro;
	p.open("settings.properties", ios::in);
	if(!p.is_open()){
		p.close();
		p.open("settings.properties", ios::out);
		p << "Made by leo900807. All rights reserved.\n";
		p << "#Vocabulary tester settings properties\n";
		p << "#Tue Jul 23 21:53:42 CST 2018\n";
		p << "file=voc_U9~U12.in\n";
		p << "user=user\n";
		p << "non-input message=<NULL>\n";
		p << "do-M mode=false\n";
		p << "penalty=5";
		p.close();
		p.open("settings.properties", ios::in);
	}
	initializer();
	f.open(file.c_str(), ios::in);
	if(!f.is_open()){
		cout << "無法開啟檔案\n\n";
		system("pause");
		return 0;
	}
	get_voc();
	get_phr();
	cout << "題數：\n\n";
	cin >> t;
	getline(cin, s);
	for(i = 1; i <= t;){
		random_shuffle(v.begin(), v.end());
		for(j = 0; i <= t && j < v.size(); i++, j++){
			system("cls");
			cout << "第 " << i << " 題    正確 " << i - 1 - w.size() << " 題    錯誤 " << w.size() << " 題    剩餘 " << t - i << " 題\n\n";
			cout << v[j].m << "\n\n";
			op = clock();
			getline(cin, s);
			all += clock() - op;
			while(s[0] == ' '){
				s.erase(s.begin());
			}
			while(s[s.size() - 1] == ' '){
				s.erase(s.begin() + s.size() - 1);
			}
			if(s == v[j].vo){
				cout << "\nAcccept!!\n\n";
				Sleep(500);
			}
			else{
				cout << "\nWrong Answer!!\n";
				cout << "\n" << v[j].vo << "\n\n";
				w.push_back(w_voc{i, v[j].vo, v[j].m, s});
				system("pause");
			}
		}
	}
	if(dom == "true")
		dom_output();
	normal_output();
	system("pause");
}
