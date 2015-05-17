#include <iostream>
#include <utility>
#include <limits.h>
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
#include <functional>

typedef long long ll;
using namespace std;

int t, n, m;
int t_n, t_m;
int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

vector<vector<char> > field;
vector<vector<int> > num_trash;
vector<vector<int> > bynum_trash;

bool isPossible(int h, int w){
	if (h > n || h < 1 || w > m || w < 1) 
		return false;
	return 	true;
}

int trash(int h, int w){
	if (field[h][w] == 'g')
		return 1;
	else
		return 0;
}

int cnt_trash(int h, int w){	
	if (h == t_n && w == t_m) return 0;
	for (int i = 0; i < 4; i++){
		if (!isPossible(h + mmove[i][0], w + mmove[i][1])) continue;
		if (trash(h + mmove[i][0], w + mmove[i][1]))
			return 1;
	}
	return 0;
}



int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif

	cin >> n >> m;

	field = vector<vector<char> >(n + 1, vector<char>(m + 1));
	num_trash = vector<vector<int> >(n + 1, vector<int>(m + 1, INT_MAX));
	bynum_trash = vector<vector<int> >(n + 1, vector<int>(m + 1, INT_MAX));

	priority_queue<pair<int, pair<int, int > >, vector<pair<int, pair<int, int > > >, greater<pair<int, pair<int, int > > > > pq;

	int s_n, s_m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> field[i][j];
			if (field[i][j] == 'S'){
				s_n = i;
				s_m = j;
			}
			if (field[i][j] == 'F'){
				t_n = i;
				t_m = j;
			}
		}
	}

	pq.push(make_pair(0, make_pair(s_n, s_m)));
	num_trash[s_n][s_m] = 0;
	pair<int, pair<int, int > > temp;
	while (!pq.empty()){
		temp = pq.top();
		pq.pop();
		int here_trash = temp.first;
		int here_h = temp.second.first;
		int here_w = temp.second.second;
		for (int i = 0; i < 4; i++){
			int there_h = here_h + mmove[i][0];
			int there_w = here_w + mmove[i][1];
			if (isPossible(there_h, there_w)){
				int cost = trash(there_h, there_w) + here_trash;
				if (num_trash[there_h][there_w] > cost){
					num_trash[there_h][there_w] = cost;
					pq.push(make_pair(cost, make_pair(there_h, there_w)));
				}
			}
		}
	}
	int limit = num_trash[t_n][t_m];
	priority_queue<pair<int, pair<int, pair<int, int > > >, vector<pair<int, pair<int, pair<int, int > > > >, greater<pair<int, pair<int, pair<int, int > > > > >pq2;

	pq2.push(make_pair(0, make_pair(0, make_pair(s_n, s_m))));
	bynum_trash[s_n][s_m] = 0;

	pair<int, pair<int, pair<int, int > > > temp2;

	while (!pq2.empty()){
		temp2 = pq2.top();
		pq2.pop();
		int here_trash = temp2.first;
		int byhere_trash = temp2.second.first;
		int here_h = temp2.second.second.first;
		int here_w = temp2.second.second.second;
		for (int i = 0; i < 4; i++){
			int there_h = here_h + mmove[i][0];
			int there_w = here_w + mmove[i][1];
			if (isPossible(there_h, there_w)){
				if (here_trash + trash(there_h, there_w) != num_trash[there_h][there_w]) continue;
				int cost = cnt_trash(there_h, there_w) + byhere_trash;
				if (bynum_trash[there_h][there_w] > cost){
					bynum_trash[there_h][there_w] = cost;
					pq2.push(make_pair(here_trash + trash(there_h, there_w), make_pair(cost, make_pair(there_h, there_w))));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cout << num_trash[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cout << bynum_trash[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << num_trash[t_n][t_m] << " " << bynum_trash[t_n][t_m] << endl;
}
