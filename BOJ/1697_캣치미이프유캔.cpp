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
int mmax;

int getIndex(int here, int i)
{
	int index;
	if(i == 0) index = here * 2;
	if(i == 1) index = here - 1;
	if(i == 2) index = here + 1;
	if(index < 0 || index > mmax * 2) return -1;
	else return index;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	vector<int> DP(200001, INF);
	queue<pair<int, int> > que;
	DP[n] = 0;
	(n > m) ? mmax = n : mmax = m;
	que.push(make_pair(n, 0));
	while(1)
	{
		int here = que.front().first;
		int herecnt = que.front().second;
		que.pop();
		for(int i = 0; i<3; i++)
		{
			int index = getIndex(here, i);
			if(index == -1) continue;
			if(DP[index] > herecnt + 1)
			{
				DP[index] = herecnt + 1, que.push(make_pair(index, herecnt + 1));
			}
		}
		if(DP[m] != INF)
		{
			cout << DP[m] << endl;
			return 0;
		}
	}
}
