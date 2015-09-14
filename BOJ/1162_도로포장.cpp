#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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

const int M = 100010;
int n, m, k;

class data{
public:
	int v;
	int w;
	int paved;
	data() :v(0), w(0), paved(0){};
	data(int a, int b, int c) :v(a), w(b), paved(c){};
	bool operator>(const data &a)const {
		return w > a.w;
	}
};

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif	
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<pair<int, int > > > graph(n + 1);
	for (int i = 0; i < m; i++){
		int t, h, w;
		scanf("%d %d %d", &t, &h, &w);
		graph[t].push_back(make_pair(h, w));
		graph[h].push_back(make_pair(t, w));
	}
	vector<vector<int> > dis(k + 1, vector<int>(n + 1, INT_MAX));
	dis[0][1] = 0;
	priority_queue<data, vector<data>, greater<data> >  pq;
	pq.push(data(1, 0, 0));
	int here, cost, paved;
	while (!pq.empty()){
		here = pq.top().v;
		cost = pq.top().w;
		paved = pq.top().paved;
		pq.pop();
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i].first;
			int there_cost = graph[here][i].second + cost;
			if (paved < k && dis[paved + 1][there] > cost){
				pq.push(data(there, cost, paved + 1));
				dis[paved + 1][there] = cost;
			}
			if (dis[paved][there] > there_cost){
				pq.push(data(there, there_cost, paved));
				dis[paved][there] = there_cost;
			}
		}
	}
	int mmin = INT_MAX;
	for (int i = 0; i <= k; i++) mmin = min(dis[i][n], mmin);
	cout << mmin << endl;
}