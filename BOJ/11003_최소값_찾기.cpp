//
// Created by  이강호 on 2016. 1. 30..
// sliding window ..

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include <deque>

using namespace std;

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n, k;
    deque<pair<int, int > > dq;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        while(!dq.empty() && dq.back().second > num)
            dq.pop_back();
        dq.push_back({i, num});
        if(i - dq.front().first >= k)
            dq.pop_front();
        printf("%d ", dq.front().second);
    }
    puts("");
}

