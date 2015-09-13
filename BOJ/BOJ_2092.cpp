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

ll dp[201][4001], cnt[210], ans = 0;

int main()
{
    freopen("input.txt", "r", stdin);
    int t, a, s, b, idx = 0;
    cin >> t >> a >> s >> b;
    vector<ll> vi(a);

    for(int i = 0; i < a; i++)
        scanf("%lld", &vi[i]);

    sort(vi.begin(), vi.end());
    cnt[0]++;
    for(int i = 1; i < a; i++){
        if(vi[i] != vi[i - 1])
            cnt[++idx]++;
        else
            cnt[idx]++;
    }
    
    dp[0][0] = 1;
    for(int i = 0; i < t; i++){
        for(int j = 0; j <=a; j++){
            for(int k = 0; k <=cnt[i]; k++){
                dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j]) % 1000000;
            }
        }
    }
    for(int i = s; i<= b; i++){
        ans = (ans + dp[t][i]) % 1000000;
    }
    cout << ans % 1000000 << endl;
}