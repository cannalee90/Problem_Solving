//
// Created by  이강호 on 2016. 2. 2..
// A와 B가 모두 홀수갯수가 아닐 경우에는 그냥 자기내들끼리 미칭해도 최대 갯수가 나온다
// 하지만 모두 홀수 일 경우 홀수간선 -> 홀수간선이 있는지만 체크해주면 가능하다

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

#define INF 987654321

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n, m, k;
    int added = 0;
    cin >> n >> m;
    if(n % 2 == 1 && m % 2 == 1) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u % 2 == 1 && v % 2 == 1) {
                added = 1;
                break;
            }
        }
    }
    cout << (n / 2) + (m / 2) + added << endl;
}
