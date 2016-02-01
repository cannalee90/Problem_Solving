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


int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<pair<double, double> > vd(n);
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            cin >> vd[i].first >> vd[i].second;
        }
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(vd[j].first < vd[i].first && vd[j].second > vd[i].second && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        printf("%d\n", *max_element(dp.begin(), dp.end()));
    }
}

