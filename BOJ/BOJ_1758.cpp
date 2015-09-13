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
  cin >> n;
  vector<int> vi(n);
  for(int i = 0; i < n; i++) 
    cin >> vi[i];
  sort(vi.begin(), vi.end());
  reverse(vi.begin(), vi.end());
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    if(vi[i] - i > 0)
      ans += vi[i] - i;
  }
  cout << ans << endl;
}
