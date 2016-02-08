//
// Created by  이강호 on 2016. 2. 8..
// dp

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

int dp[2][3000][3000];
int numHash[1000001];

int solve(int flag, int here, int next, vector<int> &vi) {
    int& ret = dp[flag][here][next];
    if(ret != -1) return ret;
    int nextV = vi[next] + vi[next] - vi[here];
    ret = 0;


    if(numHash[nextV] == -1 || nextV > 1000000 ) {
        if(flag == 0) return ret;
        else return ret = vi[here] + vi[next];
    } else {
        return ret = vi[here] + solve(1, next, numHash[nextV], vi);
    }
}

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> vi(n);
    memset(numHash, -1, sizeof(numHash));
    memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n; i++) {
        cin >> vi[i];
        numHash[vi[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = max(solve(0, i, j, vi), ans);
        }
    }
    cout << ans << endl;
}

