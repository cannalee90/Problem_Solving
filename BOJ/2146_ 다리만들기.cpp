#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stack>

#define INF 987654321
typedef long long ll;

using namespace std;

int board[110][110];
bool visited[110][100];
int n;
int mmove[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool isPossible(int h, int w) {
    if(h > n || w > n || h < 1 || w < 1) return false;
    return true;
}

void bfs(int h, int w, int num) {
    queue<pair<int, int > > que;
    que.push(make_pair(h, w));
    visited[h][w] = true;
    board[h][w] = num;
    while(!que.empty()) {
        int hereH = que.front().first;
        int hereW = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nextH = hereH + mmove[i][0];
            int nextW = hereW + mmove[i][1];
            if(isPossible(nextH, nextW) && !visited[nextH][nextW] && board[nextH][nextW] != 0) {
                que.push(make_pair(nextH, nextW));
                visited[nextH][nextW] = true;
                board[nextH][nextW] = num;
            }
        }
    }
}

int bfs2(int h, int w) {
    int ret = INF;
    int dist[110][110];
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int > > que;
    que.push(make_pair(h, w));
    dist[h][w] = 0;
    int hereNum = board[h][w];
    while(!que.empty()) {
        int hereH = que.front().first;
        int hereW = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nextH = hereH + mmove[i][0];
            int nextW = hereW + mmove[i][1];
            if(!isPossible(nextH, nextW)) continue;
            if(board[nextH][nextW] != hereNum && board[nextH][nextW] != 0){
                ret = min(ret, dist[hereH][hereW]);
            }
            if(board[nextH][nextW] == 0 && dist[nextH][nextW] == -1) {
                dist[nextH][nextW] = dist[hereH][hereW] + 1;
                que.push(make_pair(nextH, nextW));
                
            }
        }
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n; j++) {
            cin >> board[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(!visited[i][j] && board[i][j] != 0) {
                bfs(i, j, ++cnt);
            }
        }
    }
    int mmin = INF;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(board[i][j] != 0) {
                mmin = min(bfs2(i, j), mmin);
            }
        }
    }
    cout << mmin << endl;
}

//bfs한번으로도 풀 수 있다.
