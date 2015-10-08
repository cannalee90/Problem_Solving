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

typedef long long ll;


using namespace std;

int n, m, test;

vector<int> color;
vector<vector<bool > > graph;
int track[10];
int ans = 0;
ll dp[20][20][20];

void brute_force(int length, int c, int idx){
	if (length == m){
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (color[i] > 1){
			for (int j = 0; j < graph[i].size(); j++){
				if (!graph[i][j]){
					color[i]--;

					graph[i][j] = 1;
					brute_force(length + 1, i, j);
					graph[i][j] = 0;
					color[i]++;

				}
			}
		}
		else if(color[i] == 1 && color[i-1] == 0){
			for (int j = 0; j < graph[i].size(); j++){
				if (!graph[i][j]){
					color[i]--;

					graph[i][j] = 1;
					brute_force(length + 1, i, j);
					graph[i][j] = 0;
					color[i]++;

				}
			}
		}
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	color = vector<int>(n + 1);
	graph = vector<vector<bool> >(n + 1);
	for (int i = 1; i <=n; i++){
		cin >> color[i];
		graph[i].resize(color[i]);
		m += color[i];
	}
	brute_force(0, 0, 0);
	cout << ans << endl;
}