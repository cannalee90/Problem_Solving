#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <map>
#define INF 987654321
typedef long long ll;

using namespace std;

void dfs(vector<vector<int> >& graph, vector<int>& ans, vector<int>& check, int here) {
    for(int next: graph[here]) {
        if(check[next]) continue;
        check[next] = true;
        ans[next] = here;
        dfs(graph, ans, check, next);
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int> > graph(n + 1);
    vector<int> ans(n + 1);
    vector<int> check(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u , v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    check[1] = true;
    dfs(graph, ans, check, 1);
    for(int i = 2; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
}