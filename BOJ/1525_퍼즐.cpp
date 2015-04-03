#include <iostream>
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

typedef long long ll;
using namespace std;

vector<vector<char> > temp(3, vector<char>(3));

int mmove[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

int make_number(int num, int move_idx){
	int t1 = num;
	int zero_idx = 0;
	for (int i = 2; i >= 0; i--){
		for (int j = 2; j >= 0; j--){
			temp[i][j] = (t1 % 10) + '0';
			t1 /= 10;
			if (temp[i][j] == '0')

				zero_idx = i * 3 + j;
		}
	}
	if (move_idx == 0 && zero_idx <= 2)
		return num;
	else if (move_idx == 1 && zero_idx % 3 == 0)
		return num;
	else if (move_idx == 2 && zero_idx >= 6)
		return num;
	else if (move_idx == 3 && (zero_idx + 1) % 3 == 0)
		return num;
	else {
		int h = zero_idx / 3;
		int w = zero_idx % 3;
		swap(temp[mmove[move_idx][0] + h][mmove[move_idx][1] + w], temp[h][w]);
		string a = "";
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				a += temp[i][j];
			}
		}
//		cout << a << endl;
		return stoi(a);
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string begin;
	for (int i = 0; i < 9; i++){
		char t1;
		cin >> t1;
		begin += t1;
	}
	
	queue<pair<int, int> > que;
	set<int> visited;
	visited.insert(stoi(begin));
	que.push(make_pair(stoi(begin), 0));
	sort(begin.begin(), begin.end());

	int last = stoi(begin) * 10;
	if (last == que.front().first){
		cout << "0" << endl;
		return 0;
	}
	while (!que.empty()){
		int here = que.front().first;
		int here_dis = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++){
			int num = make_number(here, i);
			if (num == here)
				continue;
			else if (!visited.count(num)){
				visited.insert(num);
				que.push(make_pair(num, here_dis + 1));
				if (num == last){
					cout << here_dis + 1 << endl;
					return 0;
				}
			}
		}
	}
	cout << "-1" << endl;
}