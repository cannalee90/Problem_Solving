#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <iomanip>
#define INF 900000000


typedef long long ll;
using namespace std;
int n;

int getIndex(vector<string> &answer, string a)
{
	for(int i= 0; i<n; i++)
	{
		if(a == answer[i]) return i;
	}
	return -1;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	string t1;
	vector<string> reply;
	vector<string> answer;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		reply.push_back(t1);
	}
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		answer.push_back(t1);
	}
	int score = 0;
	for(int i= 0; i<n; i++)
	{
		int index = getIndex(answer, reply[i]);
		if(index == -1) continue;
		for(int j = 1; j<n; j++)
		{
			if(j + index >= n) break;
			if(j + i >= n) break;
			if(reply[j + i] == answer[j + index])
				score++;
		}
	}
	cout << score << "/"<<  (n * ((n - 1) / 2)) << endl;
}
