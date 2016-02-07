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


int main() {
    int n, m;
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    cin >> n;
    vector<int> vi(n), rdp(n), dp(n);
    for(int i = 0;i < n; i++)
        cin >> vi[i];
    for(int i = 0; i < n; i++) {
        int mmax = 1;
        for(int j = 0; j < i; j++) {
            if(vi[i] > vi[j])
                mmax = max(dp[j] + 1, mmax);
        }
        dp[i] = mmax;
    }
    for(int i = n -1; i >= 0; i--) {
        int mmax = 1;
        for(int j = i + 1; j < n; j++) {
            if(vi[i] > vi[j]) {
                mmax = max(rdp[j] + 1, mmax);
            }
        }
        rdp[i] = mmax;
    }
    int ans = 0;
    for(int i = 0;i < n; i++) {

        ans = max(dp[i] + rdp[i], ans);
    }
    cout << ans - 1 << endl;

}

