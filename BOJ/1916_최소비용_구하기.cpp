#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF 900000000

typedef long long ll;

using namespace std;

int n, m;
vector < vector< pair<int, int> > > graph(1010);

ll dijk(ll begin, ll eend)
{
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	vector<int> visited(1010, 99999999);
	pq.push(make_pair(0, begin));
	while(!pq.empty())
	{
		ll here = pq.top().second;
		ll dis = pq.top().first;
		if(visited[here] < dis) {pq.pop(); continue; }
		for(int i = 0; i<graph[here].size(); i++)
		{
			if(visited[graph[here][i].first] > graph[here][i].second + dis)
			{
				pq.push(make_pair(graph[here][i].second + dis, graph[here][i].first));
				visited[graph[here][i].first] = graph[here][i].second + dis;
			}
		}
		pq.pop();
	}
	return visited[eend];
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll t1, t2, begin, eend, t3;
	cin >> n >> m;
	for(int i = 0; i<m; i++)
	{
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		graph[t1].push_back(make_pair(t2,t3));
	}
	cin >> begin >> eend;
	cout << dijk(begin, eend) << endl;
}
