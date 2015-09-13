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
  freopen("../input.txt", "r", stdin);
  int n, m, k;
  cin >> n >> m >> k;
  if(n + 1 < m + k || n > m * k) {
    cout << "-1" << endl;
    return 0;
  }
  vector<int> dp(n);
  for(int i = 0; i < n; i++)
    dp[i] = i + 1;
  int idx = k;
  reverse(dp.begin(), dp.begin() + idx);
  int total = n - k;
  m--;
  while(idx < n) {

    int num;
    if(total % m == 0){
      num = total / (m);
    }
    else
      num = total / (m) + 1;
    reverse(dp.begin() + idx, dp.begin() + min(idx + num, n));
    idx += num;
    total -= num;
    m--;
  }
  for(int i : dp)
    cout << i << " ";
  puts("");
}