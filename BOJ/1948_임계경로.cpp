#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

#define INF 900000000
  
  
typedef long long ll;
using namespace std;
  
int n, m;
int bbegin, eend;
int total;
int check[10010];
bool map[10010][10010];
vector< vector<pair<int, int> > > graph;
int result[10010];
int final;
int route[10010];


 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    int t1,t2,t3;
	vector<pair<int, int> > total;
    cin >> n >> m;
	graph.resize(n+1);
    for(int i = 0; i<m; i++)
    {
		scanf("%d %d %d", &t1, &t2, &t3);
        graph[t1].push_back(make_pair(t2,t3));
        map[t1][t2] = 1;
    }
    cin >> bbegin >> eend;
    priority_queue< pair<int, int> , vector <pair<int, int> >, less<pair<int, int> > > pq;
    vector<ll> distance(n + 1,0);
    pq.push(make_pair(0,bbegin));
	route[bbegin] = -1;
    while(!pq.empty())
    {
        int here = pq.top().second;
        int here_dis = pq.top().first;
        if(distance[here] > here_dis)
        {
            pq.pop();
            continue;
        }
        pq.pop();
        for(int i = 0; i<graph[here].size(); i++)
        {
            int there = graph[here][i].first;
            int there_dis = graph[here][i].second;
            if(distance[there] <= there_dis + here_dis)
            {
				route[there] = here;
				if(there == eend)
				{
					if(distance[there] < there_dis + here_dis)
					{
						total.clear();
					}
					int h = route[there], t = eend;
					while(h != -1)
					{
						total.push_back(make_pair(h, t));
						t = h;
						h = route[h];
					}
				}
                distance[there] = there_dis + here_dis;
                pq.push(make_pair(there_dis + here_dis, there));
            }
        }
    }
	int cnt  = 0;
	for(int i = 0; i<total.size(); i++)
	{
		int here = total[i].first;
		int there = total[i].second;
		cnt += map[here][there];
		map[here][there] = 0;
	}
    cout << distance[eend] << endl;
	cout << cnt << endl;
}