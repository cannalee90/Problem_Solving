#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

#define INF 987654321


int n;
vector<vector<int> > graph;
vector<vector<int> > rgraph;
vector<vector<int> > compress;
vector<int> sccIdx;
stack<int> st;

void SCC(int size) {
	n = size;
	graph.resize(n);
	rgraph.resize(n);
	sccIdx.resize(n, -1);
}

void add_edge(int u, int v) {
	graph[u].push_back(v);
	rgraph[v].push_back(u);
}

void dfs(int here, vector<bool> &visited) {
	visited[here] = true;
	for(int next: graph[here]) {
		if(!visited[next])
			dfs(next, visited);
	}
	st.push(here);
}

void rdfs(int here, vector<bool> &visited, vector<int> &path) {
	visited[here] = true;
	path.push_back(here);
	for(int next: rgraph[here]) {
		if(!visited[next]) {
			rdfs(next, visited, path);
		}
	}
}

void process() {
	vector<bool> visited(n, false);
	vector<bool> rvisited(n, false);
	for(int i = 0; i < n; i++) {
		if(!visited[i])
			dfs(i, visited);
	}
	while(!st.empty()) {
		int here = st.top();
		st.pop();
		if (!rvisited[here]) {
			vector<int> path;
			rdfs(here, rvisited, path);
			for(int v : path) {
				sccIdx[v] = compress.size();
			}
			compress.push_back(path);
		}
	}
}

int critical_point(const vector<vector<int> > &graph, const vector<int> &vertex, vector<int> &critical, int here, int last) {
	if(here == last)
		return vertex[here];
	int &ret = critical[here];
	if(ret != -INF)
		return ret;
	for(int next : graph[here]) {
		ret = max(ret, critical_point(graph, vertex, critical, next, last) + vertex[here]);
	}
	return ret;
}


int main() {
	freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r" , stdin);
	int m, source, sink;
	cin >> n >> m >> source >> sink;
	SCC(n);
	for(int i = 0;i < m; i++) {
		int u, v;
		cin >> u >> v;
		add_edge(--u, --v);
	}
	source--, sink--;
	process();

	int size = compress.size();
	vector<int> critical(size, -987654321);
	vector<bool> visited(size, false);
	vector<vector<int> > cgraph(size);#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

	using namespace std;
	typedef long long ll;

#define INF 987654321


	int n;
	vector<vector<int> > graph;
	vector<vector<int> > rgraph;
	vector<vector<int> > compress;
	vector<int> sccIdx;
	stack<int> st;

	void SCC(int size) {
		n = size;
		graph.resize(n);
		rgraph.resize(n);
		sccIdx.resize(n, -1);
	}

	void add_edge(int u, int v) {
		graph[u].push_back(v);
		rgraph[v].push_back(u);
	}

	void dfs(int here, vector<bool> &visited) {
		visited[here] = true;
		for(int next: graph[here]) {
			if(!visited[next])
				dfs(next, visited);
		}
		st.push(here);
	}

	void rdfs(int here, vector<bool> &visited, vector<int> &path) {
		visited[here] = true;
		path.push_back(here);
		for(int next: rgraph[here]) {
			if(!visited[next]) {
				rdfs(next, visited, path);
			}
		}
	}

	void process() {
		vector<bool> visited(n, false);
		vector<bool> rvisited(n, false);
		for(int i = 0; i < n; i++) {
			if(!visited[i])
				dfs(i, visited);
		}
		while(!st.empty()) {
			int here = st.top();
			st.pop();
			if (!rvisited[here]) {
				vector<int> path;
				rdfs(here, rvisited, path);
				for(int v : path) {
					sccIdx[v] = compress.size();
				}
				compress.push_back(path);
			}
		}
	}

	int critical_point(const vector<vector<int> > &graph, const vector<int> &vertex, vector<int> &critical, int here, int last) {
		if(here == last)
			return vertex[here];
		int &ret = critical[here];
		if(ret != -INF)
			return ret;
		for(int next : graph[here]) {
			ret = max(ret, critical_point(graph, vertex, critical, next, last) + vertex[here]);
		}
		return ret;
	}


	int main() {
		freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r" , stdin);
		int m, source, sink;
		cin >> n >> m >> source >> sink;
		SCC(n);
		for(int i = 0;i < m; i++) {
			int u, v;
			cin >> u >> v;
			add_edge(--u, --v);
		}
		source--, sink--;
		process();

		int size = compress.size();
		vector<int> critical(size, -987654321);
		vector<bool> visited(size, false);
		vector<vector<int> > cgraph(size);
		vector<int> vertex(size);
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < compress[i].size(); j++) {
				for(int k = 0; k < graph[compress[i][j]].size();  k++) {
					int v = sccIdx[graph[compress[i][j]][k]];
					if (i == v || v == -1) continue;
					cgraph[v].push_back(i);
				}
			}
			sort(cgraph[i].begin(), cgraph[i].end());
			cgraph[i].erase(unique(cgraph[i].begin(), cgraph[i].end()), cgraph[i].end());
			vertex[i] = compress[i].size();
		}
		visited[sccIdx[source]] = true;
		int ans = critical_point(cgraph, vertex, critical, sccIdx[sink], sccIdx[source]);
		if(ans > 0 ) {
			cout << ans << endl;
		}else {
			cout << "0" << endl;
		}
	}
	vector<int> vertex(size);
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < compress[i].size(); j++) {
			for(int k = 0; k < graph[compress[i][j]].size();  k++) {
				int v = sccIdx[graph[compress[i][j]][k]];
				if (i == v || v == -1) continue;
				cgraph[v].push_back(i);
			}
		}
		sort(cgraph[i].begin(), cgraph[i].end());
		cgraph[i].erase(unique(cgraph[i].begin(), cgraph[i].end()), cgraph[i].end());
		vertex[i] = compress[i].size();
	}
	visited[sccIdx[source]] = true;
	int ans = critical_point(cgraph, vertex, critical, sccIdx[sink], sccIdx[source]);
	if(ans > 0 ) {
		cout << ans << endl;
	}else {
		cout << "0" << endl;
	}
}