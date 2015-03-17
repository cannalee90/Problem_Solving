#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF 90000000

using namespace std;

typedef long long ll;

vector < vector< pair < ll, ll> > > graph(810);

int n, m;

class comp
{
public:
	bool operator()(const pair<ll, ll> &a, const pair<ll, ll>&b)
	{
		return a.first < b.first;
	}
};

ll dijkstra(ll begin, ll end)
{
	ll vertex, distance;
	priority_queue<pair<ll, ll> , vector<pair<ll, ll> > , greater<pair<ll, ll> > > pq;
	vector <ll> dis(n + 2, INF);
	pq.push(make_pair(0, begin));
	dis[begin] = 0;
	while(!pq.empty())
	{
		vertex = pq.top().second;
		distance = pq.top().first;
		if(dis[vertex] < distance)
		{
			pq.pop();
			continue;
		}
		dis[vertex] = distance;
 		for(int i = 0; i<graph[vertex].size(); i++)
		{
			if(dis[graph[vertex][i].first] > distance + graph[vertex][i].second)
				pq.push(make_pair(distance + graph[vertex][i].second, graph[vertex][i].first));
		}
		pq.pop();
	}
	return dis[end];
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll t1,t2,t3;
	ll dis;
	ll node1, node2 = 2;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> t1 >> t2 >> t3;
		graph[t1].push_back(make_pair(t2,t3));
		graph[t2].push_back(make_pair(t1,t3));
	}
	cin >> node1 >> node2;
	ll between = dijkstra(node1, node2);
	ll result = min(between + dijkstra(1,node1) + dijkstra(node2,n), between + dijkstra(1, node2) + dijkstra(node1, n));
	if(result > INF)
		cout << "-1" << endl;
	else
		cout << result << endl;
}
