#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
#include <utility>
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

typedef long long ll;


using namespace std;

vector<vector<int > > graph;
int cost[501], dp[501], indegree[501];

int sol(int vertex){
	int &ret = dp[vertex];
	if (graph[vertex].size() == 0){
		ret = cost[vertex];
		return ret;
	}
	if (ret != 0) return ret;
	int mmax = 0;
	for (int i = 0; i < graph[vertex].size(); i++){
		int there = graph[vertex][i];
		mmax = max(sol(there), mmax);
	}
	dp[vertex] = mmax + cost[vertex];
	return dp[vertex];
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	graph = vector<vector<int> >(n + 1);
	for (int i = 1; i <=n; i++){
		cin >> cost[i];
		int t1;
		while (cin >> t1){
			if (t1 == -1) break;
			else graph[i].push_back(t1);
			indegree[t1]++;
		}
	}
	for (int i = 1; i <=n; i++){
		if (indegree[i] == 0){
			sol(i);
		}
	}
	for (int i = 1; i <= n; i++) cout << dp[i] << endl;
}