#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <string>
#include <cstring>
#include <ctype.h>
#include <cmath>
#include <algorithm>

typedef long long ll;

#define INF 987654321
using namespace std;


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, int > > > graph(n + 1);
    for(int i = 0; i < m;i ++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    int source, sink;
    scanf("%d %d", &source, &sink);
    priority_queue<pair<int, int > > pq;
    vector<bool> visited(n + 1, false);
    pq.push({INF + INF, source});
    while(!pq.empty()){
        int here = pq.top().second;
        int hereMax = pq.top().first;
        pq.pop();
        if(here == sink) {
            cout << hereMax << endl;
            exit(0);
        }
        if(visited[here]) continue;
        visited[here] = true;
        for(auto next : graph[here]) {
            int there = next.first;
            int thereMax = min(next.second, hereMax);
            if(!visited[there]) {

                pq.push({thereMax, there});
            }
        }
    }
}
