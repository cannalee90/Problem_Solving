#include <cstdio>
#include <vector>

typedef long long ll;
using namespace std;

int traversal(const vector<vector<int> > &graph, vector<bool> &visited, int vertex){
	int res = 0;
	for (int i = 0; i < graph[vertex].size(); i++){
		int there = graph[vertex][i];
		if (!visited[there]){
			visited[there] = true;
			res += traversal(graph, visited, there);
		}
	}
	return res + 1;
}

int main(){
	int t;
	int n, m;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		vector<vector<int> > graph(n + 1);
		vector<vector<int> > rgraph(n + 1);
		for (int i = 0; i < m; i++){
			int t, h;
			scanf("%d %d", &h, &t);
			graph[h].push_back(t);
			rgraph[t].push_back(h);
		}
		for (int i = 1; i <= n; i++){
			vector<bool> visited(n + 1, false);
			visited[i] = true;
			printf("%d %d\n", traversal(rgraph, visited, i) - 1, traversal(graph, visited, i) - 1);
		}
	}
}