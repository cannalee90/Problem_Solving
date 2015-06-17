#include <iostream>
#include <climits>
#include <functional>
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

typedef long long ll;
using namespace std;

int n, m, test;
vector<int> parent, ranking;

class edge{
public:
	int h;
	int t;
	int w;
	bool operator<(edge a) const {
		return w < a.w;
	}
};

int finding(int vertex){
	if (parent[vertex] == vertex)
		return vertex;
	else{
		parent[vertex] = finding(parent[vertex]);
		return parent[vertex];
	}
}

void merging(int p1, int p2){
	if (ranking[p1] >= ranking[p2]){
		parent[p2] = p1;
		ranking[p1] += ranking[p2];
	}
	else{
		parent[p1] = p2;
		ranking[p2] += ranking[p1];
	}
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> test;
	for (int i = 0; i < test; i++){
		int p, q;
		bool ans = false;
		cin >> n >> m;
		cin >> p >> q;
		vector<edge> edges(m);
		for (int i = 0; i < m; i++)
			cin >> edges[i].h >> edges[i].t >> edges[i].w;
		sort(edges.begin(), edges.end());
		parent = vector<int>(n + 1);
		ranking = vector<int>(n + 1);
		for (int i = 1; i <= n; i++){
			parent[i] = i;
			ranking[i] = 1;
		}
		for (int i = 0; i < m; i++){
			int h = edges[i].h, t = edges[i].t;
			int h_p = finding(h), t_p = finding(t);
			if (h_p != t_p){
				merging(h_p, t_p);
				if ((h == p && t == q) || (t == p && h == q))
					ans = true;
			}
		}
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}