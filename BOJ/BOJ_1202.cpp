#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <cmath>
 
typedef long long ll;
using namespace std;
 
#define pb push_back
#define mp(a, b) make_pair((a), (b));
 
int main()
{
    ll n, m;
    ll ans = 0, idx = 0;
    cin >> n >> m;
    vector<pair<ll, ll > > jewel(n);
    vector<ll> bp(m);
    multiset<ll> bp2;
    for (int i = 0; i < n; i++)
        cin >> jewel[i].second >> jewel[i].first;
    for (int i = 0; i < m; i++){
        cin >> bp[i];
        bp2.insert(bp[i]);
    }
 
    sort(jewel.begin(), jewel.end());
 
    reverse(jewel.begin(), jewel.end());
 
    for (int i = 0; i < n; i++) {
        auto itor = bp2.lower_bound(jewel[i].second);
        if (itor != bp2.end()) {
            ans += jewel[i].first;
            bp2.erase(itor);
        }
         
    }
 
    cout << ans << endl;
}