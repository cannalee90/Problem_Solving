#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>

#define INF 987654321
typedef long long ll;

using namespace std;

bool cmp(const pair<int, int >& a, const pair<int, int>& b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    ll n;
    cin >> n;
    vector<pair<int, int> > vp;
    for(int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        vp.push_back(make_pair(p, d));
    }
    sort(vp.begin(), vp.end(), cmp);
    vector<int> slot(10001, -1);
    for(int i = 0; i < n; i++) {
        auto cur = vp[i];
        for(int j = cur.second; j >= 1; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <=10000; i++) {
        if(slot[i] != -1) {
            ans += vp[slot[i]].first;
        }
    }
    cout << ans << endl;
}
//유명한 그리디 알고리즘 schedule with deadline
//일단 profit 순서대로 정렬한 다음(nondecreasing order)만약 이걸 할 수 있으면 하고 그렇지 않으면 pass)

