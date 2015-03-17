#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
    
#define N 1002
 
typedef long long ll;
 
 
using namespace std;
 
ll n, Nedge, d;
 
int graph[N][N];
vector <ll> path;
 
bool dfs(int vertex, int edges)
{
    path.push_back(vertex);
    if(edges == Nedge / 2 && path.front() == path.back())
    {
        for(int i = 0; i<path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
		return 1;
    }
    for(int i = 1; i<=n; i++)
    {
        if(graph[vertex][i])
        {
            graph[vertex][i] --;
            graph[i][vertex] --;
            if(dfs(i, edges +=1)) return 1;
            graph[vertex][i] ++;
            graph[i][vertex] ++;
            path.pop_back();
            edges--;
        }
    }
}
 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    ll odd = 0;
	ll begin;
    for(int i = 1; i<=n; i++)
    {
        ll t1 = 0;
        for(int j = 1; j<=n; j++)
        {
            scanf("%lld", &graph[i][j]);
            Nedge += graph[i][j];
            t1 += graph[i][j];
        }
        if(t1 % 2 != 0) odd++;
		else begin = i;
    }
    if(odd == 0 || odd == 2)
    {
		if(dfs(begin, 0)) return 0;
    }
    else
        cout << "-1"<< endl;
}