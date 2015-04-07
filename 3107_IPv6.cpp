#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string str;
	int cnt = 0;
	string str_pri;
	cin >> str;
	bool flag = true;
	int idx = 0;
	for (int i = 0; i < str.size() - 1; i++){
		if (str[i] == ':' && str[i + 1] == ':'){
			flag = false;
		}
	}
	int before = 0;
	int after = 0;
	if (!false){
		for (int i = 0; i < idx; i++){
			if (str[i] == ':'){
				before++;
			}
		}
		for (int i = idx + 1; i <str.size(); i++){
			if (str[i] == ':'){
				after++;
			}
		}
	}
	for (int i = 0; i < str.size(); i++){
		char cur = str[i];
		if (cur == ':'){
			if (str_pri.size() == 0 && !flag){
				for (int i = before + after; i <=7; i++)
					cout << "0000:";
				flag = true;
				continue;
			}
			else{
				for (int i = str_pri.size(); i < 4; i++)
					cout << "0";
				cout << str_pri;
			}
			str_pri.clear();
			cout << ":";
		}
		else{
			str_pri += cur;
		}
	}
	for (int i = str_pri.size(); i < 4; i++)
		cout << "0";
	cout << str_pri;
	cout << endl;
}