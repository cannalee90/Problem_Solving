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
    ll n, ans = 0;
    priority_queue<ll> pq;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        pq.push(num);
    }
    for(int i = 1; i <= n; i++) {
        if(i % 3 != 0)
            ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}
