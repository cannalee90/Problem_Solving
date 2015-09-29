#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;


int main() {
  freopen("../input.txt", "r", stdin);
  ll t, n, a, b;
  cin >> t;
  while(cin >> n >> a >> b) {
    ll val = 1, num = min(a, b), ans = 0;
    for (ll i = 0; i < n; i++)
      val *= 2;
    priority_queue<ll, vector<ll> , greater<ll> > pq;
    pq.push(val);
    while(num) {
      if(pq.top() > num) {
        ans++;
        ll temp = pq.top();
        pq.pop();
        pq.push(temp/ 2);
        pq.push(temp /2);
      }
      else {
        num -= pq.top();
        pq.pop();
      }
    }
    cout << ans << endl;
  }
}