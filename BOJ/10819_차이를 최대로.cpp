//
// Created by  이강호 on 2016. 2. 3..
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
#include <map>

using namespace std;

#define INF 987654321
int n, m;


int main() {
    int n;
    cin >> n;
    vector<int> vi(n);
    for(int i = 0; i < n;i++)
        cin >> vi[i];
    sort(vi.begin(), vi.end());
    int ans = -INF;
    do {
        int tmp = 0;
        for(int i = 0; i < n - 1; i++) {
            tmp += abs(vi[i] - vi[i+1]);
        }
        ans = max(ans, tmp);
    }while(next_permutation(vi.begin(), vi.end()));
    cout << ans << endl;
}

