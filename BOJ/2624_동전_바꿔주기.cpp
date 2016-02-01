//
// Created by  이강호 on 2016. 2. 1..
//


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

using namespace std;

int dp[101][10001];


int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n, m;
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<pair<int, int > > coins(m);
    for(int i = 0; i < m ;i++) {
        cin >> coins[i].first >> coins[i].second;
    }
    sort(coins.begin(), coins.end());
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++) {
        dp[i-1][0] = 1;
        for(int j = 1; j <= coins[i-1].second; j++) {
            for(int k = coins[i -1].first * j; k <= n; k++) {
                dp[i][k] += dp[i-1][k - coins[i-1].first * j];
            }
        }
        for(int j = 1; j <= n; j++) {
            dp[i][j] += dp[i-1][j];
        }
    }
    cout << dp[m][n] << endl;
}

