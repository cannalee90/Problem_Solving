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

class edge{
public:
	int here;
	int there;
	int weight;
	edge(int h, int t, int w){
		this->here = h;
		this->there = t;
		this->weight = w;
	}
	bool operator <(const edge &a) const {
		return this->weight < a.weight;
	}
};

vector<int> ranking;
vector<int> parent;
int num_set;

int finding(int vertex){
	if (parent[vertex] == vertex){
		return vertex;
	}
	else{
		int p = finding(parent[vertex]);
		parent[vertex] = p;
		return p;
	}
}

void merging(int here_p, int there_p){
	int here_r = ranking[here_p];
	int there_r = ranking[there_p];
	if (here_r > there_r){
		parent[there_p] = here_p;
		ranking[here_p] += there_r;
	}
	else{
		parent[here_p] = there_p;
		ranking[there_p] += here_r;
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	vector<edge> roads;

	for (int i = 0; i < m; i++){
		int h, t, w;
		scanf("%d %d %d", &h, &t, &w);
		roads.push_back(edge(h, t, w));
	}
	sort(roads.begin(), roads.end());
	ranking.resize(n + 1, 1);
	parent.resize(n + 1, 0);
	num_set = n;

	for (int i = 1; i <= n; i++)
		parent[i] = i;
	long long ans = 0;
	for (int i = 0; i < m; i++){

		int here = roads[i].here;
		int there = roads[i].there;
		int here_p = finding(here);
		int there_p = finding(there);

		if (here_p == there_p)
			continue;
		else{
			merging(here_p, there_p);
			ans += roads[i].weight;
			num_set--;
		}
		if (num_set == 2) 
			break;
	}
	cout << ans  << endl;
}