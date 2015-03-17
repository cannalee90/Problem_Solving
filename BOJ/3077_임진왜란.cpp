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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	string a;
	cin >> n;
	vector<string> reply;
	vector<string> answer;
	vector <pair<string, string> > data;
	for(int i = 0; i<n; i++)
	{
		cin >> a;
		reply.push_back(a);
	}
	for(int i = 0; i<n; i++)
	{
		cin >> a;
		answer.push_back(a);
	}
	for(int i = 0; i<n; i++)
	{
		for(int j = i + 1; j<n; j++)
		{
			data.push_back(make_pair(reply[i], reply[j]));
		}
	}
	int cnt = 0;
	sort(data.begin(), data.end());
	for(int i = 0; i<n; i++)
	{
		for(int j = i + 1; j<n; j++)
		{
			if(binary_search(data.begin(), data.end(), make_pair(answer[i], answer[j])))
				cnt++;
		}
	}
    cout << cnt << "/" << n * (n - 1) / 2 << endl;
	}
	