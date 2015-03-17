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

int n, m, idx = 1;
vector<int> data;
vector<int> maxTree;
vector<int> minTree;

void makeTree()
{
	while(idx < n) idx *=2;
	maxTree.resize(idx * 2 + 1, INF * -1);
	minTree.resize(idx * 2 + 1, INF);
	for(int i = 0; i <n; i++)
	{
		maxTree[i + idx] = data[i];
		minTree[i + idx] = data[i];
	}
	for(int i = idx - 1; i>= 1; i--)
	{
		maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
		minTree[i] = min(minTree[i* 2], minTree[i * 2 + 1]);

	}

}


int maxQuery(int left, int right)
{
	left += idx -1;
	right += idx -1;
	int mmax = -INF;
	while(left <= right)
	{
		if(left % 2 == 1){mmax = max(mmax, maxTree[left++]);}
		if(right % 2 == 0){mmax = max(mmax, maxTree[right--]);}
		left /= 2, right /= 2;
	}
	return mmax;
}

int minQuery(int left, int right)
{
	left += idx -1;
	right += idx -1;
	int mmin = INF;
	while(left <= right)
	{
		if(left % 2 == 1){mmin = min(mmin, minTree[left++]);}
		if(right % 2 == 0){mmin = min(mmin, minTree[right--]);}
		left /= 2, right /= 2;
	}
	return mmin;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1, left, right;
	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &t1);
		data.push_back(t1);
	}
	makeTree();
	while(m--)
	{
		scanf("%d %d", &left, &right);
		printf("%d %d\n", minQuery(left, right), maxQuery(left, right));
	}
}
