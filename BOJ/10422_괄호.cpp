#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 10000007
#define INF 10000009
#define INF 900000000


typedef long long ll;
using namespace std;

string track;
int n;
int cnt;

void dfs(int open, int close)
{
	if(open == close && open + close == n)
	{
		cout << track << endl;
		return;
	}
	if(open < n / 2)
	{
		track.push_back('(');
		dfs(open + 1, close);
		track.pop_back();
	}
	if(close < open && close < n / 2)
	{
		track.push_back(')');
		dfs(open, close + 1);
		track.pop_back();
	}
}
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	for(int i = 2; i<=8; i+=2)
	{
		cnt = 0;
		n = i;
		dfs(0, 0);
		cout << cnt << endl;
	}

}
