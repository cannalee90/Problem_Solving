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
    int n, m;
    cin >> n;
    vector<int> vi(n), dp(n);
    for(int i = 1;i  < n; i++) {
        cin >> vi[i];
    }
    dp[0] = vi[0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(vi[j] < vi[i]) {
                dp[i] = max(dp[i], dp[j] + vi[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}

