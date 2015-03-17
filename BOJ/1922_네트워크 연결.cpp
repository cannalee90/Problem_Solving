#include <iostream>
#include <utility>
#include <fstream>
#include <functional>
#include <limits.h>
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

vector<vector<pair<int, int > > > graph;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int m;
	int last_edges;
	int ans = 0;
	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int here, there, weight;
		cin >> here >> there >> weight;
		graph[here].push_back(make_pair(there, weight));
		graph[there].push_back(make_pair(here, weight));

	}
	vector<bool> added(n + 1, false);
	last_edges = 1;
	added[last_edges] = true;
	priority_queue < pair<int, int>, vector< pair<int, int > >, greater < pair<int, int > > > pq;
	n -= 1;
	while (n)
	{
		int min_weight = INT_MAX;
		int min_vertex;
		for (int i = 0; i < graph[last_edges].size(); i++)
		{
			int there = graph[last_edges][i].first;
			int weight = graph[last_edges][i].second;
			pq.push(make_pair(weight, there));

		}
		while(!pq.empty())
		{
			int there = pq.top().second;
			int weight = pq.top().first;
			pq.pop();
			if (added[there] == false && weight < min_weight)
			{
				min_weight = weight;
				min_vertex = there;
				break;
			}
		}
		n--;
//		printf("from %d to %d weighted %d\n", last_edges, min_vertex, min_weight);
		added[min_vertex] = true;
		ans += min_weight;
		last_edges = min_vertex;
	}
	cout << ans << endl;
}
