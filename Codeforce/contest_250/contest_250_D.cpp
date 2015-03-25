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

class edge{
public:
	int here;
	int there;
	int weight;
	edge(int here, int there, int weight){
		this->here = here;
		this->there = there;
		this->weight = weight;
	}

	bool operator <(const edge &a) const
	{
		return this->weight > a.weight;
	}
};

int n, m;
vector<long long> vertex;
vector<edge> edges;
vector<long long> ranking;
vector<long long> parent;

int find_parent(int vertex){
	if (parent[vertex] == vertex){
		return vertex;
	}
	else{
		parent[vertex] = find_parent(parent[vertex]);
		return parent[vertex];
	}
}

void merging(int here_p, int there_p){
	if (here_p >= there_p){
		parent[there_p] = here_p;
		ranking[here_p] += ranking[there_p];
	}
	else{
		parent[here_p] = there_p;
		ranking[there_p] += ranking[here_p];

	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	double ans = 0;
	cin >> n >> m;
	vertex.resize(n + 10, 0);
	parent.resize(n + 10, 0);
	ranking.resize(n + 10, 1);
	for (int i = 1; i <= n; i++){
		parent[i] = i;
	}
	for (int i = 1; i <=n; i++){
		cin >> vertex[i];
	}
	for (int j = 0; j < m; j++){
		int here, there, weight;
		cin >> here >> there;
		edges.push_back(edge(here, there, min(vertex[here], vertex[there])));
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < m; i++){
		int here = edges[i].here;
		int there = edges[i].there;
		int weight = edges[i].weight;
		int here_p = find_parent(here);
		int	there_p = find_parent(there);
		if (here_p == there_p || here_p == 0 || there_p == 0)
			continue;
		else{
			ans += (double)(ranking[here_p] * ranking[there_p]) * (double)weight;
			merging(here_p, there_p);
		}
	}
	printf("%lf", (ans * 2) / ((double)(n)* (double)(n - 1)));
}	