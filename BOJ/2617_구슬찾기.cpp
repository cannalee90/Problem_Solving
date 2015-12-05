#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>

#define INF 987654321
typedef long long ll;

using namespace std;

int dfs(vector<vector<int> >& graph, vector<bool>& check, int here) {
    int ret = 1;
    for(int next: graph[here]) {
        if(check[next]) continue;
        check[next] = true;
        ret += dfs(graph, check, next);
    }
    return ret;
}



int main() {
    int n, m;
    cin >>n >> m;
    vector<vector<int> > graph(n + 1);
    vector<vector<int> > rgraph(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    vector<bool> check(n + 1, false);
    vector<bool> rcheck(n + 1, false);
    vector<bool> ans(n + 1);
    for(int i = 1; i <=n; i++) {
        fill(check.begin(), check.end(), false);
        fill(rcheck.begin(), rcheck.end(), false);
        check[i] = true;
        rcheck[i] = true;
        if(dfs(graph, check, i) > (n + 1) / 2)
            ans[i] = true;
        if(dfs(rgraph, rcheck, i) > (n + 1) / 2)
            ans[i] = true;
    }
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        if(ans[i])
            cnt++;
    }
    cout << cnt << endl;
}
