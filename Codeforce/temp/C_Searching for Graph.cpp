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

int n, p, test;
int graph[30][30];
bool isDone;

void constrcut_graph(int cnt){
	if (isDone) return;
	if (cnt == 0){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++)
				if (graph[i][j] == 1) cout << i << " " << j << endl;
		}
		isDone = true;
		return;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (graph[i][j] == 0){
				graph[i][j] = 1;
				constrcut_graph(cnt - 1);
				graph[i][j] = 0;
			}
		}
	}

}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> test;
	while (test--){
		cin >> n >> p;
		memset(graph, 0, sizeof(graph));
		isDone = false;
		constrcut_graph(2 * n + p);
	}
}