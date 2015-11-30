//
//  main.cpp
//  Hello World
//
//  Created by  이강호 on 2015. 11. 27..
//  Copyright © 2015년 cannalee90. All rights reserved.
//

#include <string>
#include <iostream>

#define INF 987654321
using namespace std;

int floyd[500][500];

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            floyd[i][j] = INF;
        }
    }
    for(int i = 0; i < m ;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        floyd[u][v] = w;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <=n; j++) {
                if(floyd[i][j] > floyd[i][k] + floyd[k][j])
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, floyd[i][i]);
    }
    if(ans == INF)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}

