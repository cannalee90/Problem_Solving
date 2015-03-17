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

vector<vector<int> > tree;
vector<int> data;
int n, m;

vector<int> slice(vector<int> data, int b, int e)
{
	vector<int> slice;
	for(int i = b; i<e; i++)
	{
		slice.push_back(data[i]);
	}
	return slice;
}

void traversal(vector<int> data, int height)
{
	if(data.size() == 1)
	{
		tree[height].push_back(data[0]);
		return;
	}
	int rootidx = data.size() / 2;
	int length = data.size();
	traversal(slice(data, 0, rootidx), height + 1);
	traversal(slice(data, rootidx+ 1, length), height + 1);
	tree[height].push_back(data[rootidx]);
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1;
	cin >> n;
	tree.resize(n);
	m = pow((double)2, n) - 1;
	for(int i = 0; i<m; i++)
	{
		cin >> t1;
		data.push_back(t1);
	}
	traversal(data, 0);
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<tree[i].size(); j++)
		{
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}
}
