//
// Created by  이강호 on 2016. 2. 8..
//
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <string>
#include <cstring>
#include <ctype.h>
#include <cmath>
#include <set>
#include <algorithm>
#include <sstream>

typedef long long ll;

#define INF 987654321
using namespace std;

int t, n;

void dfs(vector<vector<int> > &graph, vector<bool> &visited, int here) {
    visited[here] = true;
    for(int next : graph[here]) {
        if(!visited[next])
            dfs(graph, visited, next);
    }
}

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        vector<vector<int> > graph(n + 1);
        for(int i = 1; i <= n; i++) {
            int v;
            scanf("%d", &v);
            graph[i].push_back(v);
        }
        vector<bool> visited(n + 1);
        int ans = 0;
        for(int i = 1; i<= n; i++) {
            if(!visited[i]) {
                dfs(graph, visited, i);
                ans++;
            }
        }
        cout << ans << endl;
    }
}


