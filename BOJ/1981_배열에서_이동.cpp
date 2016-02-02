//
// Created by  이강호 on 2016. 2. 2..
// 생각을 잘못해서 너무 힘들었던 문제이다
// 솔루션은 간단하다 위이건 아래건 리밋을 정해놓고 다익스트라를 돌리는 것
// 다익스트라를 돌릴 때, 정의를 항상 생각하고 돌려야 한다.
// 그래프처럼 생각하고 돌렸다가 visited[i][j] > current 처럼 돌리면 답이 안나오다
// 그리고 민맥스를 저장하고 bfs를 돌리면 역시 답이 안나온다. 같을때 처리하는 방법이 없기 때문


#include<stdio.h>
#include<iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <deque>
#include <queue>
#include <tuple>
#include <stack>
#include <unordered_set>
#include <map>

using namespace std;

#define INF 987654321
int n, m;

struct comp{
    int h, w, c;
    comp(int h, int w, int c) : h(h), w(w), c(c) {}
    bool operator < (const comp & a) const {
        return this->c > a.c;
    }
};

bool isRange(int h, int w) {
    if(h < 0 || w < 0 || h >= n || w >= n) return false;
    else return true;
}


int  isPossible(int limit, const vector<vector<int> > &board) {
    int mmove[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    priority_queue<comp> que;
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    que.push(comp(0,0, board[0][0]));
    while(!que.empty()) {
        int nowH = que.top().h;
        int nowW = que.top().w;
        int nowV = que.top().c;
        que.pop();
        if(nowH == n- 1 && nowW == n-1) return nowV;
        for(int i = 0; i < 4; i++) {
            int nextH = nowH + mmove[i][0];
            int nextW = nowW + mmove[i][1];
            if(isRange(nextH, nextW)) {
                int nextV = max(board[nextH][nextW], nowV);
                if(board[nextH][nextW] >= limit && visited[nextH][nextW] == false) {
                    que.push(comp(nextH, nextW, nextV));
                    visited[nextH][nextW] = true;
                }
            }
        }
    }
    return 2000;
}

int main() {
    cin >> n;
    vector<vector<int> > board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",  &board[i][j]);
        }
    }

    int ans = INF;

    for(int i = 0; i <= board[0][0]; i++) {
        ans = min(isPossible(i, board) - i, ans);
    }
    cout << ans << endl;
}

