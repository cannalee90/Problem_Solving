#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

#define INF
const long long  hash_value =  1000000000000000007;
                               

typedef long long ll;
using namespace std;

vector<vector<int > > graph;
vector<bool> visited;
vector<string> words;
vector<int> in;
vector<int> out;

int n;

void initialize()
{
	graph.clear();
	visited.clear();
	words.clear();
	in.clear();
	out.clear();
	in.resize(n + 1);
	out.resize(n + 1);
	graph.resize(28, vector<int>(28, 0));
	visited.resize(n + 1);
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
		cin >> n;
		string a;
		initialize();
		for(int i = 0; i<n; i++)
		{
			cin >> a;
			words.push_back(a);
		}
		for(int i = 0; i<n; i++)
		{
			int in = words[i][0] - 'a';
			int out = words[i][words.size() -1] - 'a';
			graph[in][out]++;

		}
	}
}