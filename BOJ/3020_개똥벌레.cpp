//
// Created by  이강호 on 2016. 2. 5..
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

typedef long long ll;

#define INF 987654321
using namespace std;

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> upper;
    vector<int> lower;
    vector<int> vi;
    vi.push_back(0);
    vi.push_back(m * 2);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if(i % 2 == 0) {
            lower.push_back(num * 2);
            vi.push_back(num * 2);
        }
        else {
            upper.push_back(num * 2);
            vi.push_back((m - num) * 2);
        }
    }
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());
    sort(vi.begin(), vi.end());
    vi.erase(unique(vi.begin(), vi.end()), vi.end());

    int ans = INF;
    int ansCnt = 0;
    for(int i = 1; i < m * 2; i+= 2)  {

        int mid = i;
        auto lo = lower.end() - upper_bound(lower.begin(), lower.end(), mid);
        auto hi = upper.end() - upper_bound(upper.begin(), upper.end(), (m * 2) - mid);

        if(ans > (lo + hi)) {
            ans = (lo + hi);
            ansCnt = 1;
        }else if(ans == lo + hi){
            ansCnt++;
        }
    }
    cout << ans << " " << ansCnt << endl;
}