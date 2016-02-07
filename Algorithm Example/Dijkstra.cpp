struct Dijkstra {
	int n;
	vector<vector<pair<int, int > > > graph;
	Dijkstra(int size) {
		this->n = size;
		graph.resize(n);
	}
	void add_edge(int u, int v, int cost) {
		graph[u].push_back(make_pair(v, cost));
	}
	vector<int> process(int u, int v) {
		vector<int> dist(n, 987654321);
		dist[u] = 0;
		priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > > pq;
		pq.push(make_pair(0, u));
		while(!pq.empty()) {
			int hereDist = pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if(dist[here] < hereDist) continue;
			for(int i = 0; i < graph[here].size(); i++) {
				int there = graph[here][i].first;
				int thereDist = graph[here][i].second + hereDist;
				if(thereDist < dist[there]) {
					dist[there] = thereDist;
					pq.push(make_pair(thereDist, there));
				}
			}
		}
		return dist;
	}
};
