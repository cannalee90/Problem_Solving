#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <stack>

#define INF 987654321

using namespace std;

struct dijkstra {
    vector<vector<pair<int, int > > > graph;
    vector<int> parent;
    vector<int> dis;
    int n;
    dijkstra(int n) {
        this->n = n;
        graph = vector<vector<pair<int, int > > >(n + 1);
    }
    void add_edge(int u, int v, int w) {
        graph[u].push_back(make_pair(v, w));
    }
    void find_sp(int source, int sink, int u, int v) {
        parent = vector<int>(n + 1, -1);
        dis = vector<int>(n + 1, INF);
        
        dis[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int > >, greater<pair<int, int > > > pq;
        pq.push(make_pair(0, source));
        while(!pq.empty()) {
            int here = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if(dis[here] < cost) continue;
            for(int i = 0; i < graph[here].size(); i++) {
                int next = graph[here][i].first;
                int nextDis = graph[here][i].second + cost;
                if(next == v && here == u) continue;
                if(here == v && next == u) continue;
                if(dis[next] > nextDis) {
                    dis[next] = nextDis;
                    parent[next] = here;
                    pq.push(make_pair(nextDis, next));
                }
            }
        }
    }
};

int main() {
    int n, m;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    dijkstra dijk(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dijk.add_edge(u, v, w);
        dijk.add_edge(v, u, w);
    }
    dijk.find_sp(1, n, 0, 0);
    int ans = -INF;
    int u = n;
    vector<int> parent = dijk.parent;
    while(dijk.parent[u] != -1) {
        dijk.find_sp(1, n , u , parent[u]);
        ans = max(ans, dijk.dis[n]);
        u =  parent[u];
    }
    cout << ans << endl;
}
