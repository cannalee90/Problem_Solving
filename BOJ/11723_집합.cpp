//
// Created by  이강호 on 2016. 1. 31..
//

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include <cstring>
#include <bitset>
#include <deque>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;

int n, m;


int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    freopen("/Users/kangho/Documents/Problem_Solving/output.txt", "w+", stdout);

    int n;
    scanf("%d", &n);
    bitset<21> set;
    while(n--) {
        char query[10];
        int num;
        scanf("%s", &query);
        if(query[0] == 'a' && query[1] == 'd') {
            scanf("%d", &num);
            set.set(num, 1);
        }else if(query[0] == 'c') {
            scanf("%d", &num);
            if(set.test(num)) {
                puts("1");
            }else {
                puts("0");
            }
        }else if(query[0] == 'r') {
            scanf("%d", &num);
            set.set(num, 0);
        }else if(query[0] == 't') {
            scanf("%d", &num);
            set.flip(num);
        }else if(query[0] == 'a' && query[1] == 'l') {
            set.reset();
            set.flip();
        }else {
            set.reset();
        }
    }
}

