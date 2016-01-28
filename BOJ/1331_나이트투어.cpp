//
// Created by  이강호 on 2016. 1. 29..
//

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

bool isPossible(pair<int, int > &here, pair<int, int > &there, int idx) {
    int mmove[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1,2}, {1,-2},{-1,2},{-1,-2}};
    if(here.first + mmove[idx][0] == there.first && here.second + mmove[idx][1] == there.second)
        return true;
    else
        return false;
}

int main() {
    int t, n = 36;
    vector<vector<bool> > visited(10, vector<bool>(10, false));
    vector<pair<int, int > > vp;
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    for(int i = 0; i < n; i++) {
        char cur;
        int row, col;
        cin >> cur >> col;
        row = cur - 'A';
        if(visited[row][col]) {
            cout << "Invalid" << endl;
            exit(0);
        } else {
            visited[row][col] = true;
        }
        vp.push_back({row, col});
    }
    for(int i = 0; i < n; i++) {
        int cur = i;
        int next = (i == n - 1) ? 0 : i + 1;
        bool isValid = false;
        for(int i = 0; i < 8; i++) {
            if(isPossible(vp[cur], vp[next], i)) {
                isValid = true;
                break;
            }
        }
        if(!isValid) {
            cout << "Invalid" << endl;
            return 0;
        }
    }
    cout << "Valid" << endl;
}
