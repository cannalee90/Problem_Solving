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
#include <algorithm>
#include <sstream>

typedef long long ll;

#define INF 987654321
using namespace std;

char board[60][60];
int al[60][60];
int n, m;

bool isRange(int h, int w) {
    if(h >= n || w >= n || h < 0 || w < 0) return false;
    return true;
}
struct elem{
    int h;
    int w;
    int mmax;
    bool operator < (const elem& b) const {
        return this->mmax > b.mmax;
    }
    elem(int h, int w, int mmax) : h(h), w(w), mmax(mmax) {}
};

int dijk(int lo, int sh, int sw) {
    int mmove[8][2] = {{0, 1},
                       {0,-1},
                       {1, 0},
                       {-1,0},
                       {1, 1},
                       {1,-1},
                       {-1,1},
                       {-1,-1}};
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    priority_queue<elem> pq;
    pq.push(elem(sh, sw, al[sh][sw]));
    int mmax = 0;
    while(!pq.empty()){
        int hereH = pq.top().h;
        int hereW = pq.top().w;
        int hereM = pq.top().mmax;
        if(board[hereH][hereW] == 'K') {
            mmax = max(mmax, hereM);
        }
        pq.pop();
        if(visited[hereH][hereW]) continue;
        visited[hereH][hereW] = true;
        for(int i = 0; i < 8; i++) {
            int nextH = hereH + mmove[i][0];
            int nextW = hereW + mmove[i][1];
            if(isRange(nextH, nextW)) {
                int nextM = max(al[nextH][nextW], hereM);
                if (!visited[nextH][nextW] && al[nextH][nextW] >= lo) {
                    pq.push(elem(nextH, nextW, nextM));
                }
            }
        }
    }
    for(int i = 0;i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'K' && !visited[i][j])
                return INF;
        }
    }
    return mmax;
}

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    vector<int> vi;
    int sh, sw;
    int source;
    cin >> n;
    for(int i = 0;i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0;i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> al[i][j];
            vi.push_back(al[i][j]);
            if(board[i][j] == 'P') {
                source = al[i][j];
                sh = i;
                sw = j;
            }
        }
    }
    sort(vi.begin(), vi.end());
    vi.erase(unique(vi.begin(), vi.end()), vi.end());
    int ans = INF;
    for(int i = 0; i < vi.size() && source >= vi[i]; i++) {
        ans = min(ans, dijk(vi[i], sh, sw) - vi[i]);
    }
    cout << ans<< endl;
}

