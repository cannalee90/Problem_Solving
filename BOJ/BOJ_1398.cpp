#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <limits.h>
#include <cmath>
 
typedef long long ll;
using namespace std;
 
#define pb push_back
#define mp(a, b) make_pair((a), (b))

int main() {
    ll n;
    
    //freopen("input.txt", "r", stdin);
    
    vector<ll> coin;

    coin.push_back(1);
    coin.push_back(10);
    coin.push_back(25);
    coin.push_back(100);

    cin >> n;

    while(n--) {
        ll price;
        ll ans = 0;
        cin >> price;
        while(price) {
            ll temp = price % 100;
            price /= 100;   
            vector<ll> dp(temp + 1, 987654321);
            dp[0] = 0;
            for(ll i = 0; i < coin.size(); i++) {
                for(ll j = coin[i]; j <= temp; j++) {
                    if(dp[j - coin[i]] + 1 < dp[j]) {
                        dp[j] = dp[j - coin[i]] + 1;
                    }
                }
            }
            ans += dp[temp];
        }
        cout << ans << endl;
    }
} 