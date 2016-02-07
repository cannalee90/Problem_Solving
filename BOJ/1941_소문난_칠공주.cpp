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

int n = 5;
char board[5][5];
set <vector<vector<bool> > > op;
set<vector<pair<int, int > > > ans;
vector<vector<bool > > visited;

int mmove[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool isRange(int h, int w) {
    if(h >= 5 || w >= 5 || h < 0 || w < 0) return false;
    return true;
}

void dfs(int h, int w, int cnt, vector<pair<int, int > >& trail){
    visited[h][w] = true;
    if(op.count(visited)) {
        return;
    }else {
        op.insert(visited);
    }
    if(cnt == 7){
        int tmp = 0;
        for(int i = 0;i < trail.size(); i++) {
            int th = trail[i].first;
            int tw = trail[i].second;
            if(board[th][tw] == 'S')
                tmp++;
        }
        if(tmp >= 4) {
            ans.insert(trail);
        }
        return;
    }
    for(int k = 0; k < trail.size(); k++) {
        for (int i = 0; i < 4; i++) {
            int nextH = trail[k].first + mmove[i][0];
            int nextW = trail[k].second + mmove[i][1];
            if (isRange(nextH, nextW) && !visited[nextH][nextW]) {
                trail.push_back({nextH, nextW});
                dfs(nextH, nextW, cnt + 1, trail);
                visited[nextH][nextW] = false;
                trail.pop_back();
            }
        }
    }
}

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);

    for(int i = 0; i < n; i++) {
        for(int j = 0;j < n; j++)
            cin >> board[i][j];
    }
    vector<pair<int, int > > trail;
    visited.resize(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            trail.push_back({i,j});
            dfs(i, j, 1, trail);
            visited[i][j] = false;
            trail.pop_back();
        }
    }
    cout << ans.size() << endl;
}

