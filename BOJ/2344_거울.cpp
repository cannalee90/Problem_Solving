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
map<pair<int, int >, int > result;
vector<pair<int, pair<int, int > > > vp;

int mmove[4][2] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
int mirror[1010][1010];

bool isInBox(int h, int w){
	if (h < 1 || h > n || w < 1 || w > m) return false;
	return true;
}

int change(int t){
	if (t == 0) return 1;
	if (t == 1) return 0;
	if (t == 2) return 3;
	if (t == 3) return 2;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int cnt = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		vp.push_back(make_pair(cnt, make_pair(i, 0)));
		result[make_pair(i, 0)] = cnt;
		cnt++;
	}
	for (int i = 1; i <= m; i++){
		vp.push_back(make_pair(cnt, make_pair(n + 1, i)));
		result[make_pair(n + 1, i)] = cnt;
		cnt++;
	}
	for (int i = n; i >= 1; i--){
		vp.push_back(make_pair(cnt, make_pair(i, m + 1)));
		result[make_pair(i, m + 1)] = cnt;
		cnt++;
	}
	for (int i = m; i >= 1; i--){
		vp.push_back(make_pair(cnt, make_pair(0, i)));
		result[make_pair(0, i)] = cnt;
		cnt++;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &mirror[i][j]);
		}
	}
	for (int i = 0; i < vp.size(); i++){
		int h = vp[i].second.first;
		int w = vp[i].second.second;
		int type = 3;
		if (1 <= vp[i].first && vp[i].first <= n) type = 0;
		else if (n < vp[i].first && vp[i].first <= m + n) type = 1;
		else if (n + m < vp[i].first && vp[i].first <= 2 * n + m) type = 2;
		h += mmove[type][0];
		w += mmove[type][1];
		while (isInBox(h, w)){
			if (mirror[h][w] == 1)
				type = change(type);
			h += mmove[type][0];
			w += mmove[type][1];
		}
		printf("%d ", result[make_pair(h, w)]);
	}
}