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
vector<pair<int, int > >  dots;
int parent[501];
int ranking[501];

class edges{
public:
	int h = 0;
	int t = 0;
	double w = 0;
	bool operator<(const edges &a)const {
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

void merge(int p, int q){
	p = finding(p);
	q = finding(q);
	if (ranking[p] >= ranking[q]){
		ranking[p] += ranking[q];
		parent[q] = p;
	}
	else{
		ranking[q] += ranking[p];
		parent[p] = q;
	}
}

double caldis(int a, int b){
	int x = dots[a].first - dots[b].first;
	int y = dots[a].second - dots[b].second;
	return sqrt((double)(x * x) + (double)(y * y));
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> test;
	while (test--){
		cin >> n >> m;
		double ans = 0;

		dots = vector<pair<int, int > >(n);

		for (int i = 0; i < n; i++) cin >> dots[i].first;
		for (int i = 0; i < n; i++) cin >> dots[i].second;
		for (int i = 0; i < n; i++) {parent[i] = i; ranking[i] = 1;}

		for (int i = 0; i < m; i++){
			int p, q;
			cin >> p >> q;
//			ans += caldis(p, q);
			merge(p, q);
		}
		edges e;
		vector<edges> ve;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (finding(i) == finding(j)) continue;
				e.h = i;
				e.t = j;
				e.w = caldis(i, j);
				ve.push_back(e);
			}
		}
		sort(ve.begin(), ve.end());
		for (int i = 0; i < ve.size(); i++){
			int p = finding(ve[i].h);
			int q = finding(ve[i].t);
			if (p != q){
				merge(p, q);
				ans += ve[i].w;
			}
		}
		printf("%.10lf\n", ans);
	}
}