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

vector<pair<int, int> > tree;
vector<int > v;
int clue;

int findParent(vector<bool> &check)
{
	for(int i = 1; i<=check.size(); i++)
	{
		if(check[i] == 0) return i;
	}
}

void traverse(int node)
{
	if(tree[node].first != 0)
		traverse(tree[node].first);
	if(tree[node].second != 0)
		traverse(tree[node].second);
	if(tree[node].first != 0 && v[tree[node].first] >= v[node])
	{
		clue = 1;
	}
	if(tree[node].second != 0 && v[tree[node].second] <= v[node])
	{
		clue = 1;
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int clue = 1;
		cin >> n;
		tree.resize(n + 1, pair<int, int>());
		v.resize(n + 1,0);
		vector<bool> check(n + 1, 0);
		vector<int> check2(1001, 0);
		for(int i = 1; i<=n; i++)
		{
			int L, R, K;
			cin >> L >> R >> K;
			tree[i].first = L;
			tree[i].second = R;
			check[L] = 1;
			check[R] = 1;
			v[i] = K;
			check2[K]++;
			if(check2[K] == 2) clue = 2;
		}
		int root = findParent(check);
		clue = 0;
		traverse(root);
		if(clue == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
