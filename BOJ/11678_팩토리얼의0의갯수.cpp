#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stack>
#include <map>

#define INF 987654321
typedef long long ll;

using namespace std;

int fac(int mid) {
    int ret = 0;
    int base = 5;
    while(mid / base) {
        ret += mid / base;
        base *= 5;
    }
    return ret;
}


int main() {
    int n;
    cin >> n;
    int left = 1, right = 500000000;
    int ans = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        int cntZero = fac(mid);
        if(cntZero == n) {
            ans = mid;
        }
        if(cntZero < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
}

