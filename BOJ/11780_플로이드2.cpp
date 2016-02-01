//
// Created by  이강호 on 2016. 1. 26..
//

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

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

int main() {
    int n, m;
    cin >> n >> m;
    Floyd floyd(n);
    for(int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--;
        v--;
        floyd.add_edge(u, v, cost);
    }
    floyd.process();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(floyd.getCost(i, j) == 987654321 || i == j)
                printf("0 ");
            else
                printf("%d ", floyd.getCost(i, j));
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            auto path = floyd.getPath(i, j);
            if(path.size() == 1) {
                printf("0");
            }else {
                printf("%d ", path.size());
                for (int k = 0; k < path.size(); k++) {
                    printf("%d ", path[k] + 1);
                }
            }
            printf("\n");
        }
    }
}