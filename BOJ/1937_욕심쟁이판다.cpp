//
// Created by  이강호 on 2016. 2. 9..
// pq with bfs but dp로도 해결 가능

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

int n;
int board[510][510];
bool visited[510][510];
int dis[510][510];

bool isRange(int h, int w) {
    if (h >= n || w >= n || h < 0 || w < 0) return false;
    return true;
}

struct elem{
    int h, w, cnt, v;
    elem(int h, int w, int cnt, int v) : h(h), w(w), cnt(cnt), v(v){}
    bool operator < (const elem &b) const {
        if(b.v == this->v) return this->cnt < b.cnt;
        else return this->v > b.v;
    }
};

int bfs() {
    int mmove[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    memset(visited, 0, sizeof(visited));
    priority_queue<elem> pq;
    for(int i = 0;i < n; i++) {
        for(int j = 0; j < n; j++) {
            pq.push(elem(i, j, 1, board[i][j]));
        }
    }
    int ret = 0;
    while(!pq.empty()){
        int hereH = pq.top().h;
        int hereW = pq.top().w;
        int hereC = pq.top().cnt;
        int hereV = pq.top().v;
        ret = max(ret, hereC);
        pq.pop();
        if(visited[hereH][hereW]) continue;
        visited[hereH][hereW] = true;
        for(int i = 0; i < 4; i++) {
            int nextH = hereH + mmove[i][0];
            int nextW = hereW + mmove[i][1];
            if(isRange(nextH, nextW)) {
                int nextV = board[nextH][nextW];
                if(nextV > hereV && dis[nextH][nextW] < dis[hereH][hereW] + 1) {
                    pq.push(elem(nextH, nextW, hereC + 1, nextV));
                    dis[nextH][nextW] = dis[hereH][hereW] + 1;
                }
            }
        }
    }
    return ret;
}

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    cout << bfs() << endl;
}
