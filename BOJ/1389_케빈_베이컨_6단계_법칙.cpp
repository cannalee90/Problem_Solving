//
// Created by  이강호 on 2016. 1. 19..
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int floyd[200][200];
int n, m;

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r" , stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n; j++) {
            floyd[i][i] = 0;
            floyd[i][j] = 987654321;
        }
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        floyd[u][v] = 1;
        floyd[v][u] = 1;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <=n; i++) {
            for(int j = 1; j<= n; j++) {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
    int mmax = 987654321;
    int ans = 0;
    for(int i = 1; i <= n;i++) {
        int ssum = 0;
        for(int j = 1; j<=n; j++) {
            ssum += floyd[i][j];
        }
        if(ssum < mmax) {
            ans = i;
            mmax = ssum;
        }
    }
    cout << ans << endl;
}