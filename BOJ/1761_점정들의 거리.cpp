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

int n, m, t;

ll dijk(int start, int des, const vector< vector<pair<int, int> > > &graph)
{
	vector<ll> dis(n + 1, INF);
	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;
	dis[start] = 0;
	pq.push(make_pair(0,start));
	while(!pq.empty())
	{
		int here_dis = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dis[here] < here_dis) 
		{
			continue;
		}
		for(int i = 0; i<graph[here].size(); i++)
		{
			int there = graph[here][i].first;
			int there_dis = graph[here][i].second;
			if(dis[there] > here_dis + there_dis)
			{
				pq.push(make_pair(here_dis + there_dis, there));
				dis[there] = here_dis + there_dis;
				if(there == des) return dis[des];
			}
		}
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1,t2,t3;
	cin >> n;
	vector< vector<pair<int, int> > > graph(n + 1);
	for(int i = 0; i<n -1; i++)
	{
		cin >> t1 >> t2 >> t3;
		graph[t1].push_back(make_pair(t2,t3));
		graph[t2].push_back(make_pair(t1,t3));
	}
	cin >> m;
	while(m--)
	{
		cin >> t1 >> t2;
		cout << dijk(t1, t2, graph) << endl;
	}
}
