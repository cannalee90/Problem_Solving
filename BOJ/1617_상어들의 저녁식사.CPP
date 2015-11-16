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

struct shark {
	int size;
	int speed;
	int wiz;
	shark(int size, int speed, int wiz) : size(size), speed(speed), wiz(wiz){}
};

bool dfs(int here, vector<vector<int> >& graph, vector<bool>& check, vector<int>& match){
	for (int& next : graph[here]) {
		if (check[next]) continue;
		check[next] = true;
		if (match[next] == -1 || dfs(match[next], graph, check, match)) {
			match[next] = here;
			return true;
		}
	}
	return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<shark> data;
	vector<vector<int> > graph(n);
	for (int i = 0; i < n; i++) {
		int size, speed, wiz;
		cin >> size >>  speed >> wiz;
		data.push_back(shark(size, speed, wiz));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (data[i].size == data[j].size && data[i].speed == data[j].speed && data[i].wiz == data[j].wiz){
				if (i < j) //상어의 크기가 같으면 서로 먹히면 안되므로.. i < j 보다 클때만 이어준다
					graph[i].push_back(j);
			}
			else if (data[i].size >= data[j].size && data[i].speed >= data[j].speed && data[i].wiz >= data[j].wiz)
				graph[i].push_back(j); 
		}
	}
	int ans = 0;
	vector<int> match(n, -1);
	vector<bool> check(n, false);
	for(int j = 0; j < 2; j++){
		for (int i = 0; i < n; i++) {
			fill(check.begin(), check.end(), false);
			if (dfs(i, graph, check, match))
				ans++;
		}
	}
	cout << n - ans << endl; 
}
