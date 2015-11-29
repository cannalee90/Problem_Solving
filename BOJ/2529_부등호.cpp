//
//  main.cpp
//  Hello World
//
//  Created by  이강호 on 2015. 11. 27..
//  Copyright © 2015년 cannalee90. All rights reserved.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
typedef long long ll;

using namespace std;

char check[10];
char sg[10];
int maxvi[10];
int minvi[10];
int n;
ll mmax = -999876543210;
ll mmin = 999876543210;

void solve(int cnt, vector<int>& vi) {
    if(cnt == n + 1) {
        ll num = 0;
        for(int i = 0; i <= n; i++) {
            num *= 10;
            num += vi[i];
        }
        bool isGood = true;
        for(int i = 0; i < n; i++) {
            if(sg[i] == '>') {
                if(vi[i] < vi[i + 1])
                    isGood = false;
            }
            if(sg[i] == '<'){
                if(vi[i] > vi[i+1])
                    isGood = false;
            }
        }
        if(isGood) {
            if(mmax < num){
                for(int i = 0; i <= n; i++)
                    maxvi[i] = vi[i];
                mmax = num;
            }
            if(mmin > num) {
                for(int i = 0; i <= n; i++)
                    minvi[i] = vi[i];
                mmin = num;
            }
            
        }
        return;
    }
    for(int i = 0; i < 10; i++) {
        if(check[i] ==0) {
            check[i] = true;
            vi.push_back(i);
            solve(cnt + 1, vi);
            check[i] = false;
            vi.pop_back();
        }
    }
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> sg[i];
    
    vector<int> vi;
    solve(0, vi);
    for(int i = 0; i <= n; i++)
        cout << maxvi[i];
    puts("");
    for(int i = 0;i <=n; i++)
        cout << minvi[i];
    puts("");
    
}

