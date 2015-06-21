#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

double graph[10][10];
bool visited[10];
int test, n, m;
double ans;

void tsp(int vertex, int cnt ,double dis){
	if (cnt == n){
		ans = min(ans, dis);
		return;
	}
	for (int i = 0; i < n; i++){
		if (!visited[i]){
			visited[i] = true;
			tsp(i, cnt + 1, dis + graph[vertex][i]);
			visited[i] = false;
		}
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> test;
	while (test--){
		cin >> n;
		memset(graph, 0, sizeof(graph));
		memset(graph, 0, sizeof(visited));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		ans = 987654321;

		for (int i = 0; i < n; i++){
			visited[i] = true;
			tsp(i, 1, 0);
			visited[i] = false;
		}
		printf("%.10lf\n", ans);
	}
}

