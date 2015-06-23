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
vector<pair<double, double> > dots;
vector<int> parent, ranking;

class edge{
public:
	int h;
	int t;
	double w;
	bool operator<(const edge &a) const{
		return w < a.w;
	}
};

int finding(int vertex){
	if (parent[vertex] == vertex) return vertex;
	else 	return parent[vertex] = finding(parent[vertex]);
}

void merge(int p, int q){
	p = finding(p);
	q = finding(q);
	if (ranking[p] > ranking[q]){
		ranking[p] += ranking[q];
		parent[q] = p;
	}
	else{
		ranking[q] += ranking[p];
		parent[p] = q;
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> test;
	while (test--){
		cin >> n;
		dots = vector<pair<double, double > >(n);
		parent = vector<int>(n);
		ranking = vector<int>(n);
		edge e;
		vector<edge> edges;
		for (int i = 0; i < n; i++) cin >> dots[i].first >> dots[i].second;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				double x = (dots[i].first - dots[j].first) * (dots[i].first - dots[j].first);
				double y = (dots[i].second - dots[j].second) * (dots[i].second - dots[j].second);
				e.h = i;
				e.t = j;
				e.w = sqrt(x + y);
				edges.push_back(e);
			}
		}
		double ans;
		sort(edges.begin(), edges.end());
		for (int i = 0; i < n; i++) parent[i] = i, ranking[i] = 1;
		for (int i = 0; i < edges.size(); i++){
			int p = finding(edges[i].h);
			int q = finding(edges[i].t);
			if (p != q){
				merge(p, q);
				ans = edges[i].w;
			}
		}
		printf("%.2lf\n", ans);
	}
}