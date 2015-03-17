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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n;
	int t1,t2;
	cin >> t;
	while(t--)
	{
		cin >> n;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		for(int i = 0; i<n; i++)
		{
			cin >> t1 >> t2;
			pq.push(make_pair(t1, t2));
		}
		int max = pq.top().second;
		int cnt = 1;
		pq.pop();
		while(!pq.empty())
		{
			if(max > pq.top().second)
			{
				cnt ++;
				max = pq.top().second;
			}
			pq.pop();
		}
		cout << cnt << endl;
	}
}
