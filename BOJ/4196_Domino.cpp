#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

#define INF 987654321

void dfs(const vector<vector<int> > &graph, vector<bool> &visited, stack<int> &st, int here){
    visited[here] = true;
    for(int next : graph[here]) {
        if(!visited[next]) {
            dfs(graph, visited, st, next);
        }
    }
    st.push(here);
}

void rdfs(const vector<vector<int> > &rgraph, vector<bool> &rvisited, vector<int> &sccIdx, int here, int cnt) {
    rvisited[here] = true;
    sccIdx[here] = cnt;
    for(int next : rgraph[here]) {
        if(!rvisited[next]) {
            rdfs(rgraph, rvisited, sccIdx, next, cnt);
        }
    }
}

void dfs3(const vector<vector<int> > &cgraph, vector<bool> &cvisited, int here) {
    cvisited[here] = true;
    for(int next : cgraph[here]) {
        if(!cvisited[next])
            dfs3(cgraph, cvisited, next);
    }
}

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > graph(n), rgraph(n);
        vector<int> sccIdx(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            graph[u].push_back(v);
            rgraph[v].push_back(u);
        }
        stack<int> st;
        vector<bool> visited(n), rvisited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, visited, st, i);
            }
        }
        int ans = 0;
        while (!st.empty()) {
            int here = st.top();
            st.pop();
            if (!rvisited[here]) {
                rdfs(rgraph, rvisited, sccIdx, here, ans);
                ans++;
            }
        }
        vector<vector<int> > cgraph(ans);
        vector<bool> cvisited(ans);
        for (int i = 0; i < n; i++) {
            for (int next: graph[i]) {
                int here = sccIdx[i];
                int there = sccIdx[next];
                cgraph[here].push_back(there);
            }
        }
        for (int i = 0; i < ans; i++) {
            sort(cgraph[i].begin(), cgraph[i].end());
            cgraph[i].erase(unique(cgraph[i].begin(), cgraph[i].end()), cgraph[i].end());
        }
        int total = 0;
        for(int i = 0; i < ans; i++) {
            if(!cvisited[i]) {
                total++;
                dfs3(cgraph, cvisited, i);
            }
        }
        cout << total << endl;
    }
}
