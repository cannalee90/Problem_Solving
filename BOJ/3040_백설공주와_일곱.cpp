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
	int n = 9;
	int data[10];

	for(int i = 0; i<n; i++)
	{
		cin >> data[i];
	}
	vector<pair<int, int> > que;
	vector<pair<int, int> > track;
	que.push_back(make_pair(0, 0));
	track.push_back(make_pair(-1, 0));
	for(int i = 0; i<n; i++)
	{
		int len = que.size();
		for(int j = 0; j<len; j++)
		{
			if(que[j].first + data[i] == 100 && que[j].second == 6)
			{
				cout << data[i] << endl;
				cout << track[j].second << endl;
				int index = track[j].first;
				while(index != 0)
				{
					cout << track[index].second << endl;
					index = track[index].first;
				}
			}
			if(que[j].first + data[i] < 100)
			{
				que.push_back(make_pair(que[j].first + data[i], que[j].second + 1));
				track.push_back(make_pair(j, data[i]));
			}
		}
	}
}
