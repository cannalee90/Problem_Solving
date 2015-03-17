#include <iostream>
#include <algorithm>
#include <vector>


typedef long long ll;
using namespace std;

int n, m;
vector<vector<int > > tree;
vector<int> result;
vector<vector<bool> > visited;


void traversal(int node, int start)
{
	int cnt = 0;
	visited[node][start] = 1, visited[start][node] = 1;
	for(int i = 0; i<tree[node].size(); i++)
	{
		int there = tree[node][i];
		if(visited[start][there] == 0)
		{
			traversal(there, start);
		}
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1, t2;
	cin >> n >> m;
	tree.resize(n + 1);
	visited.resize(n + 1,vector<bool>(n + 1, 0));
	for(int i = 0; i<m; i++)
	{
		cin >> t1 >> t2;
		tree[t1].push_back(t2);
	}
	for(int i = 1; i<=n; i++)
	{
		traversal(i, i);
	}
	for(int i = 1; i<=n; i++)
	{
		int cnt = 0;
		for(int j = 1; j<=n; j++)
		{
			if(visited[i][j]) cnt++;
		}
		cout << n - cnt << endl;
	}
}
