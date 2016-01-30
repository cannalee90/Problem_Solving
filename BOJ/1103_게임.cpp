//
// Created by  이강호 on 2016. 1. 31..
//

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include <cstring>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
bool visited[2600][60][60];

bool isRange(int h, int w) {
    if(h >= n || w >= m || h < 0 || w < 0) return false;
    return true;
}

int bfs(const vector<vector<int> > &board, int h, int w) {
    int ret = 0;
    int mmove[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    memset(visited, 0, sizeof(visited));
    queue<tuple<int, int, int > > que;
    que.push(make_tuple(h, w, 0));
    while(!que.empty()) {
        int hereH = get<0>(que.front());
        int hereW = get<1>(que.front());
        int cnt = get<2>(que.front());
        int cur = board[hereH][hereW];
        ret = max(ret, cnt);
        que.pop();

        if(cnt > n * m)
            continue;
        for(int i = 0;i < 4; i++) {
            int nextH = hereH + (mmove[i][0] * cur);
            int nextW = hereW + (mmove[i][1] * cur);
            if(isRange(nextH, nextW) && visited[cnt+ 1][nextH][nextW] == false && board[nextH][nextW] != 0) {
                que.push(make_tuple(nextH, nextW, cnt + 1));
                visited[cnt+ 1][nextH][nextW] = true;
            }
        }
    }
    return ret;
}

int main() {

    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    vector<vector<int> > board(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            char cur;
            int num = 0;
            cin >> cur;
            if(cur == 'H')
                num = 0;
            else
                num = cur - '0';

            board[i][j] = num;
        }
    }
    int ans = bfs(board, 0,0);
    if(ans > n * m)
        cout << "-1" << endl;
    else
        cout << ans + 1 <<endl;
}



