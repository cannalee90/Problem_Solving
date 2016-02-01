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
    int t;
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> s1(n);
        vector<string> s2(n);
        unordered_set<string> left(n * 2);
        unordered_set<string> right(n * 2);
        for(int i = 0; i < n; i++) {
            cin >> s1[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> s2[i];
        }
        int last = -1;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                if(right.count(s1[i])) {
                    right.erase(s1[i]);
                }else {
                    left.insert(s1[i]);
                }
                if(left.count(s2[i])) {
                    left.erase(s2[i]);
                }else {
                    right.insert(s2[i]);
                }
            }
            if(left.empty() && right.empty()) {
                cout << i - last  << endl;
                last = i;
            }
        }
    }
}

