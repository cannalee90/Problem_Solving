//
// Created by cannalee on 2016. 1. 26..
// Floyd warshall with reconstruction
// It is important to check INF value;


struct Floyd {
    int n;
    vector<vector<int> > graph;
    vector<vector<int> > next;
    Floyd(int size) {
        this->n = size;
        graph.resize(n, vector<int>(n, 987654321));
        next.resize(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++)
            graph[i][i] = 0;
    }
    void add_edge(int u, int v, int cost) {
        graph[u][v] = min(graph[u][v], cost);
        next[u][v] = v;
    }
    void process() {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(graph[i][j] > graph[i][k] + graph[k][j] && i != j) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }
    int getCost(int u, int v) {
        return graph[u][v];
    }
    vector<int> getPath(int u, int v) {
        vector<int> path = {u};
        while(true) {
            if(next[u][v] == - 1)
                break;
            else {
                u = next[u][v];
                path.push_back(u);
            }
        }
        return path;
    }
};
