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
    freopen("input.txt", "r", stdin);
    int n;
    ll cnt[2] = {};
    ll ans = 0;
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++){
        if(str[i] == 'C')
            cnt[0]++;
        else if(str[i] == 'O')
            cnt[1]+= cnt[0];
        else 
            ans += cnt[1];
    }
    cout << ans << endl;
}

