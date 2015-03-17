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
	int cnt;

	void inorder_traverse(vector< pair<int, int> > &tree, vector< pair<int, int> > &height_width, int node, int height)
	{
		if(tree[node].first != -1)
		{
			inorder_traverse(tree, height_width, tree[node].first, height + 1);
		}
		height_width[node].first = height;
		height_width[node].second = cnt++;
		if(tree[node].second != -1)
		{
			inorder_traverse(tree, height_width, tree[node].second, height + 1);
		}
	}

	int main()
	{
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
	#endif
		int t1, t2, t3;
		cin >> n;
		vector< pair<int, int> > tree(n + 1);
		vector< pair<int, int> > height_width(n + 1);
		vector< pair<int, int> > result(n + 1);
		vector< bool > check( n + 1);
		for(int i = 0; i<n; i++)
		{
			cin >> t1 >> t2 >> t3;
			tree[t1].first = t2;
			tree[t1].second = t3;
			if(t2 != -1) check[t2] = 1;
			if(t3 != -1) check[t3] = 1;
		}
		int root;
		for(int i = 1; i<=n; i++)
		{
			if(check[i] == 0)
			{
				root = i;
				break;
			}
		}
		cnt = 1;
		inorder_traverse(tree, height_width, root, 1);
		for(int i = 1; i<=n; i++)
		{
			if(result[height_width[i].first].first == 0)
			{
				result[height_width[i].first].first = height_width[i].second;
			}
			else if(result[height_width[i].first].first > height_width[i].second)
			{
				result[height_width[i].first].first = height_width[i].second;
			}
			if(height_width[height_width[i].first].second == 0)
			{
				result[height_width[i].first].second = height_width[i].second;
			}
			else if(result[height_width[i].first].second < height_width[i].second)
			{
				result[height_width[i].first].second = height_width[i].second;
			}
		}
		int max = 0;
		int maxP;
		for(int i = 1; i<=n; i++)
		{
			ll temp = 1 + (result[i].second - result[i].first);
			if(max < temp)
			{
				max = temp;
				maxP = i;
			}
		}
		printf("%d %d\n",maxP, max);
	}
