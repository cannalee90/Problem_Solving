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
vector < vector< pair<int, int> > > graph(110);

int dijk(int begin, int end)
{
	priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	vector<int> visited(n + 1, 87654321);
	pq.push(make_pair(0, begin));
	while(!pq.empty())
	{
		int here = pq.top().second;
		int here_dis = pq.top().first;

		if(visited[here] < here_dis) {pq.pop(); continue;}

		for(int i = 0; i<graph[here].size(); i++)
		{
			int there = graph[here][i].first;
			int there_dis = graph[here][i].second;
			
			if(visited[there] > here_dis + there_dis)
			{
				pq.push(make_pair(there_dis+ here_dis, there));
				visited[there] = here_dis + there_dis;
			}
		}
		pq.pop();
	}
	return visited[end];
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll begin, end;
	ll t1, t2, t3;
	cin >> n;
	cin >> begin >> end;
	cin >> m;
	for(int i = 0; i<m; i++)
	{
		cin >> t1 >> t2;
		graph[t1].push_back(make_pair(t2,1));
		graph[t2].push_back(make_pair(t1,1));
	}
	int result =  dijk(begin, end);
	if(result == 87654321)
		cout << "-1" << endl;
	else
		cout << result << endl;
}
