//
// Created by  이강호 on 2016. 1. 29..
// tropological sort with queue

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <climits>


using namespace std;
typedef long long ll;

#define INF 987654321

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> indegree(n + 1);
    vector<vector<int> > graph(n + 1);
    for(int i = 0; i < m; i++) {
        int u , v;
        scanf("%d %d", &u, &v);
        indegree[v]++;
        graph[u].push_back(v);
    }
    queue<int> que;
    for(int i = 1; i <= n;i++) {
        if(indegree[i] == 0)
            que.push(i);
    }
    while(!que.empty()) {
        int here = que.front();
        que.pop();
        printf("%d ", here);
        for(int v : graph[here]) {
            indegree[v]--;
            if(indegree[v] == 0)
                que.push(v);
        }
    }

}
