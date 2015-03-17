#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

vector <string> data;
vector < bool > isWin;
int n;


void check_out(char loser, int idx){
	for (int i = 0; i < n; i++){
		if (data[i][idx] == loser)
			isWin[i] = false;
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		isWin.clear();
		isWin.resize(n + 1, true);
		data.clear();
		for (int i = 0; i < n; i++){
			string a;
			cin >> a;
			data.push_back(a);
		}

		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (data[i].size() < data[j].size()){
					string temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
		
		for (int i = 1; i < n; i++){
			if (data[i].size() != data[0].size()){
				while (data[i].size() != data[0].size()){
					data[i].push_back(data[i].back());
				}
			}
		}

		for (int i = 0; i < data[0].size(); i++){
			map<char, int> check;
			check['R'] = 0;
			check['S'] = 0;
			check['P'] = 0;
			for (int j = 0; j < n; j++){
				if (isWin[j]){
					char idx = data[j][i];
					check[idx] ++;
				}	
			}
			int r = check['R'];
			int s = check['S'];
			int p = check['P'];
			if (r != 0 && p != 0 && s != 0){
				continue;
			}
			else if (r != 0 && p != 0 && s == 0){
				check_out('R', i);
			}
			else if (r != 0 && p == 0 && s != 0){
				check_out('S', i);
			}
			else if (r == 0 && p != 0 && s != 0){
				check_out('P', i);
			}
		}
		int cnt = 0;
		int winner;
		for (int i = 0; i < n; i++){
			if (isWin[i]) {
				cnt++;
				winner = i + 1;
			}
		}
		if (cnt == 1)
			cout << winner << endl;
		else
			cout << "0" << endl;
	}
}















