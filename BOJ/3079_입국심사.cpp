#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <list>
#include <queue>
using namespace std;

typedef long long ll;

bool isPossible(const ll people, const ll mid, const vector<int> &time) {
    ll cnt = 0;
    for(auto &num : time) {
        cnt += mid / num;
    }
    if(cnt >= people)
        return true;
    else
        return false;
}

int main() {

    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r" , stdin);
    ll n, m;
    cin >> n >> m;
    vector<int> time(n);
    for(int i = 0 ; i < n; i++) {
        cin >> time[i];
    }
    ll left = 1;
    ll right = m * (*min_element(time.begin(), time.end()));
    ll ans;

    while(left <= right) {
        ll mid = (left + right) / 2;
        if(isPossible(m, mid, time)) {
            ans = mid;
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
}