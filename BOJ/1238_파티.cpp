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

int dijk(int begin, int end, vector< vector< pair<int, int> > > &graph)
{
	priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll> > >  pq;
	pq.push(make_pair(0, begin));
	vector<ll> dis(n + 1, INF);
	dis[begin] = 0;
	while(!pq.empty())
	{
		int here = pq.top().second;
		int here_dis = pq.top().first;
		if(here_dis > dis[here])
		{
			pq.pop();
			continue;
		}
		for(int i = 0; i< graph[here].size(); i++)
		{
			int there = graph[here][i].first;
			int there_dis = graph[here][i].second;
			if(dis[there] > here_dis + there_dis)
			{
				dis[there] = here_dis + there_dis;
				pq.push(make_pair(here_dis + there_dis, there));
			}
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
	int t1, t2, t3;
	int destin;
	cin >> n >> m >> destin;
	vector< vector< pair<int, int> > > graph(n + 1);
	for(int i = 0; i<m; i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);
		graph[t1].push_back(make_pair(t2,t3));
	}
	int mmax = 0;
	for(int i = 1; i<=n; i++)
	{
		mmax = max(mmax, dijk(i, destin, graph) + dijk(destin,i,graph));
	}
	cout << mmax << endl;
}
