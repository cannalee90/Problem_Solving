#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;

		vector<string> board(n);
		vector<vector<int> > graph(n * m);
		vector<vector<bool> > visited(n * m,vector<bool>(20, false));

		for (int i = 0; i < n; i++)	
			cin >> board[i];
		int begin;
		for (int i = 0; i < m - 1; i++){
			for (int j = 0; j < n; j++){
				if (board[j][i] == '@') begin = i * n + j;
				for (int k = 0; k < n; k++){
					if(board[k][i + 1] != '#')
						graph[i * n + j].push_back((i + 1)* n + k);
				}
			}
		}
		queue<pair<int, int > > que;
		que.push(make_pair(begin, 0));
		int mmax = begin / n;
		while (!que.empty()){

			int here = que.front().first;
			int here_w = que.front().first / n;
			int here_h = que.front().first % n;

			int acc = que.front().second;

			que.pop();

			int upper = here_h - 4;
			if (upper < 0) upper = 0;
			int lower = here_h + acc + 1;
			
			for (int i = 0; i < graph[here].size(); i++){
				if (graph[here][i] == (here_w + 1) * n + upper && !visited[(here_w + 1) * n + upper][0]){
					que.push(make_pair((here_w + 1) * n + upper, 0));
					visited[(here_w + 1) * n + upper][0] = true;
					mmax = max(here_w + 1, mmax);
				}
				if (lower < n){
					if (graph[here][i] == (here_w + 1)* n + lower && !visited[(here_w + 1)* n + lower][acc+1]){
						visited[(here_w + 1)* n + lower][acc+1] = true;
						que.push(make_pair((here_w + 1)* n + lower, acc + 1));
						mmax = max(here_w + 1, mmax);
					}
				}
			}			
		}
		cout << mmax + 1 << endl;
	}
}