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
#define mp(a, b) make_pair((a), (b))

ll GCD(ll a, ll b){
  if(b == 0) return a;
  return GCD(b, a % b);
}

int main() {
  int t;
  freopen("input.txt", "r", stdin);
  scanf("%d", &t);
  while(t--) {
    int n;
    ll ans = 0;
    scanf("%d", &n);  
    vector<ll> vl(n);
    vector<pair<ll, ll> > gcd;
    for(int i = 0; i < n; i++)
      scanf("%lld", &vl[i]);
    for(int i = 0; i < n; i++) {
      gcd.pb(mp(0, i));
      for(int j = 0; j < gcd.size(); j++) {
        gcd[j].first = GCD(gcd[j].first, vl[i]);
      }
      sort(gcd.begin(), gcd.end());
      vector< pair<ll, ll> > temp;
      temp.pb(gcd[0]);
      for(int j = 1; j < gcd.size(); j++) {
        if(!j || gcd[j].first != gcd[j - 1].first) {
          temp.pb(gcd[j]);
        }
      }
      swap(temp, gcd);
     for(int j = 0; j < gcd.size(); j++) {
        ans = max(ans, ((ll)i - gcd[j].second + 1) * gcd[j].first);
      }
    
    }
      printf("%lld\n", ans);
    
  }
}
