#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;


int get_count(string str, string a, string b){
	int ans = 0;
	int cans = 0;
	vector<int> strv(30), stra(30), strb(30);
	for (int i = 0; i < str.size(); i++) strv[str[i] - 'a']++;
	for (int i = 0; i < a.size(); i++) stra[a[i] - 'a'] ++;
	for (int i = 0; i < b.size(); i++) strb[b[i] - 'a']++;
	vector<int> temp = strv, temp2 = strv;
	int cnt = 0;
	while (1){	
		int ansb = INT_MAX;
		bool isPossible = true;
		for (int i = 0; i<26; i++){
			if (strb[i] != 0){
				ansb = min(ansb, temp[i] / strb[i]);
			}
		}
		if (ans < ansb + cnt){
			cans = cnt;
			ans = ansb + cnt;
		}
		for (int i = 0; i < 26; i++){
			if (temp[i] < stra[i]){
				isPossible = false;
			}
		}
		if (!isPossible) break;
		else{
			cnt++;
			for (int i = 0; i < 26; i++)
				temp[i] -= stra[i];
		}
	}
	
	return cans;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string str, a, b;
	cin >> str >> a >> b;
	vector<int> strv(30), stra(30), strb(30);
	for (int i = 0; i < str.size(); i++) strv[str[i] - 'a']++;
	for (int i = 0; i < a.size(); i++) stra[a[i] - 'a'] ++;
	for (int i = 0; i < b.size(); i++) strb[b[i] - 'a']++;

	int ansa = get_count(str, a, b);
	for (int i = 0; i < ansa; i++){
		cout << a;
		for (int j = 0; j < 26; j++) strv[j] -= stra[j];
	}
	while (1){
		bool isPossible = true;
		for (int j = 0; j < 26; j++){
			if (strv[j] < strb[j]){
				isPossible = false;
			}
		}
		if (!isPossible) break;
		else{
			cout << b;
			for (int i = 0; i < 26; i++) strv[i] -= strb[i];
		}
	}

	for (int i = 0; i < 26; i++){
		for (int j = 0; j < strv[i]; j++){
			printf("%c", i + 'a');
		}
	}
	puts("");
}