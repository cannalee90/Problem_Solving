//
// Created by  이강호 on 2016. 1. 27..
// graph reachability

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>


using namespace std;
typedef long long ll;

#define INF 987654321

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n, m, k;
    scanf("%d %d", &n, &m);
    vector<vector<int> > floyd(n, vector<int>(n, INF));
    vector<vector<int> > rfloyd(n, vector<int>(n, INF));
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        floyd[u][v] = 1;
        rfloyd[v][u] = 1;
    }
    for(int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
                rfloyd[i][j] = min(rfloyd[i][k] + rfloyd[k][j], rfloyd[i][j]);
            }
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        if(floyd[u][v] < 1000)
            puts("-1");
        else if(rfloyd[u][v] < 1000)
            puts("1");
        else
            puts("0");
    }
}
