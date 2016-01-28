//
// Created by  이강호 on 2016. 1. 26..
// Kosaraju's algorithm (strongly connected component)

struct SCC {
    int n;
    vector<vector<int> > graph;
    vector<vector<int> > rgraph;
    vector<vector<int> > compress;
    vector<int> sccIdx;
    stack<int> st;

    SCC(int size) {
        this->n = size;
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

    vector<vector<int> > process() {
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
        return compress;
    }
    vector<int> getSCC() {
        return sccIdx;
    }
    int getSize() {
        return compress.size();
    }
    vector<vector<int> > getCompress() {
        vector<vector<int> > cgraph(compress.size());
        for(int i = 0;i < n; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                int here = sccIdx[i];
                int there = sccIdx[graph[i][j]];
                if(here == there) continue;
                cgraph[here].push_back(there);
            }
        }
        for(int i = 0; i < compress.size(); i++) {
            sort(cgraph[i].begin(), cgraph[i].end());
            cgraph[i].erase(unique(cgraph[i].begin(), cgraph[i].end()), cgraph[i].end());
        }
        return cgraph;
    }
    vector<vector<int> > getGraph() {
        return graph;
    }
};

