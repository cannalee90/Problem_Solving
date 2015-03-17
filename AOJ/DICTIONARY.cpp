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

int find_zero_indegree(vector<vector<int> > &graph, vector<int> &result, vector<bool> &check, vector<int> char_set)
{
	for(int i = 0; i<26; i++)
	{
		int cnt = 0;
		if(check[i] == 1) continue;
		if(char_set[i] == 0) continue;
		for(int j = 0; j<26; j++)
		{
			if(graph[j][i]) cnt++;
		}
		if(cnt == 0) return i;
	}

	return -1;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<string> words;
		string input;
		for(int i = 0; i<n; i++)
		{
			cin >> input;
			words.push_back(input);
		}
		graph.clear();
		graph.resize(28, vector<int>(28, 0));
		vector<int> char_set(28);
		for(int i = 0; i<n - 1; i++)
		{
			for(int j = 0; j<words[i].length(); j++)
			{
				if(j == words[i+1].length() ) break;
				int here = words[i][j] - 'a';
				int there = words[i+1][j] - 'a';
				if(here == there) continue;
				graph[here][there] = 1;
				char_set[there] = 1;
				char_set[here] = 1;
				break;
			}
		}
		vector<int> result;
		vector<bool> check(26);
		for(int p = 0; p<26; p++)
		{
			int vertex = find_zero_indegree(graph, result, check, char_set);
			if(vertex == -1) break;
			else
			{
				for(int i = 0; i<26; i++)
				{
					graph[vertex][i] = 0;
				}
				result.push_back(vertex);
				check[vertex] = 1;
			}
		}
		bool flag = 0;

		for(int i = 0; i<26; i++)
		{
			for(int j = 0; j<26; j++)
			{
				if(graph[i][j] == 1)
				{
					flag = 1;break;
				}
			}
			if(flag == 1) break;
		}
		if(flag == 1) cout << "INVALID HYPOTHESIS";
		else 
		{
			for(int i = 0; i<result.size(); i++)
			{
				printf("%c",result[i] + 'a');
			}
			for(int i = 0; i<26; i++)
			{
				if(check[i] == 0)
					printf("%c", i+'a');
			}
		}
		cout << endl;
	}
}