#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
   
using namespace std;


int n, m;


class d1
{
public:
	int vertex;
	int weight;
	d1(int vertex, int weight)
	{
		this->vertex = vertex;
		this->weight = weight;
	}
};


class cmp{
public:
	bool operator()(const d1 &t,  const d1 &u)
	{
        return t.weight > u.weight;
    }
};

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1,t2,t3, begin;
	int cnt = 0;

	long long tw = 0;
	cin >> n;
	cin >> m;
	vector< vector<d1> > graph(n + 1);
	cin >> begin;
	for(int i = 0; i<m; i++)
	{
		cin >> t1 >> t2 >> t3;
		graph[t1].push_back(d1(t2,t3));
	}
	priority_queue<d1, vector<d1>, cmp > que;

	vector<int> visited(n + 1, 99999999);

	for(int i = 1; i<=n; i++)
	{
		if(begin == i)
			que.push(d1(i,0));
		else
			que.push(d1(i,99999999));
	}

	while(!que.empty())
	{
		d1 here = que.top();
		if(visited[here.vertex] < here.weight){que.pop(); continue;}
		visited[here.vertex] = here.weight;
		m = graph[here.vertex].size();
		for(int i = 0; i<m; i++)
		{
			if(visited[graph[here.vertex][i].vertex] > graph[here.vertex][i].weight + here.weight)
				que.push(d1(graph[here.vertex][i].vertex, graph[here.vertex][i].weight + here.weight));
		}
		que.pop();
	}

	for(int i = 1; i<=n; i++)
	{
		if(visited[i] != 99999999)
			cout << visited[i] << endl;
		else 
			cout << "INF" << endl;
	}
}
