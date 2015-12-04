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


int main() {
    freopen("input.txt", "r", stdin);
    int n, m, t;
    cin >> t;
    while(t--) {
        int n;
        int total = 0;
        cin >> n;
        vector<pair<int, int > > vp;
        for(int i = 0; i < n; i++) {
            int v;
            cin >> v;
            total += v;
            vp.push_back(make_pair(v, i + 1));
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        if(vp[0].first == vp[1].first)
            cout << "no winner" << endl;
        else {
            if(vp[0].first > total / 2)
                cout << "majority winner " << vp[0].second << endl;
            else
                cout << "minority winner " << vp[0].second << endl;
        }
    }
}
