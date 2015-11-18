#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

#define INF 987654321

bool dfs(vector<vector<int> >& graph, vector<int>& match, vector<bool>& check, int here) {
	for (int& next : graph[here]) {
		if (check[next]) continue;
		check[next] = true;
		if (match[next] == -1 || dfs(graph, match, check, match[next])) {
			match[next] = here;
			return true;
		}
	}
	return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	vector<bool> prime(2001, false);
	set<int> Prime;
	for (int i = 2; i <= 2000; i++) {
		if (!prime[i]){
			Prime.insert(i);
			for (int j = i; j <= 2000; j += i)
				prime[j] = true;
		}
	}
	int n;
	cin >> n;
	set<int> ans;
	vector<int> del;
	vector<int> vi(n);
	vector<vector<int> > graph(n);
	vector<int> match(n, -1);
	vector<bool> check(n, false);
	for (int i = 0; i < n; i++)
		cin >> vi[i];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (Prime.count(vi[i] + vi[j])){
				graph[i].push_back(j);
				if (j == 0)
					del.push_back(i);
			}
		}
	}
	
	for(int k = 0; k <= del.size() ; k++){
		for (int i = 0; i < n; i++) {
			fill(check.begin(), check.end(), false);
			if (dfs(graph, match, check, i)) {
				bool isAns = true;;
				for (int j = 0; j < n; j++) {
					if (match[j] == -1)
						isAns = false;
				}
				if (isAns){
					ans.insert(vi[match[0]]);
				}
			}
		}
		if (match[0] != -1){
			graph[match[0]].erase(graph[match[0]].begin());
			fill(match.begin(), match.end(), -1);
			
		}
	}
	if (ans.size() == 0) 
		cout << "-1" << endl;
	else {
		for (auto itor = ans.begin(); itor != ans.end(); itor++)
			cout << *itor << " ";
		puts("");
	}
}
