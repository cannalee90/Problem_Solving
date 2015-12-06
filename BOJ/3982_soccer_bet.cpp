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

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        map <string, int> score;
        for(int i = 0; i < 16; i++) {
            string a, b;
            int as, bs;
            cin >> a >> b >> as >> bs;
            if(as > bs) {
                score[a]++;
            }
            else {
                score[b]++;
            }
        }
        string ans;
        int mmax = -INF;
        for (auto itor = score.begin(); itor != score.end(); itor++) {
            if(itor->second > mmax) {
                mmax = itor->second;
                ans = itor->first;
            }
        }
        cout << ans << endl;
    }
}

