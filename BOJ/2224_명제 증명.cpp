//
// Created by  이강호 on 2016. 1. 27..
// check reachability
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

#define INF 987654321

vector<vector<int> > graph(100);


int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n;
    vector<bool> check(100, false);
    vector<vector<int> > floyd(100, vector<int>(100, INF));
    cin >> n;
    for(int i = 0; i <n; i++) {
        string left, right, center;
        cin >> left >> center >> right;
        floyd[left[0] - 'A'][right[0] - 'A'] = 1;
    }
    for(int k = 0; k < 100; k++) {
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(floyd[i][j] < 100 && i != j) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(floyd[i][j] < 100 && i != j) {
                cout << (char)(i + 'A') << " => " << (char)(j + 'A') << endl;
            }
        }
    }
}
