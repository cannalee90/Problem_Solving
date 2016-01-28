//
// Created by  이강호 on 2016. 1. 28..
// sort with lambda function

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <climits>


using namespace std;
typedef long long ll;

#define INF 987654321


int main() {
    int t;
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    vector<int> a(10), b(10);
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < 10; j++) {
        cin >> b[j];
    }
    sort(a.begin(), a.end(), [](const int &a, const int &b) {
        return a > b;
    });
    sort(b.begin(), b.end(), [](const int &a, const int &b) {
        return a > b;
    });
    cout << a[0] + a[1] + a[2] << " " << b[0] + b[1] + b[2] << endl;

}
