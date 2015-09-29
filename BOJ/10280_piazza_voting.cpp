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
  int n, k;
  int lo, hi;
  int select = 0;
  cin >> n >> k;
  lo = 1;
  hi = n;
  while(hi - lo >= 1) {

    if(select == 0)
      hi--;
    else if(select == 1) 
      lo++;
    else {
      if(k - lo < hi - k) {
        hi--;
      } else {
        lo++;
      }
    }
    select++;
    select %= 3;

    
  }
  if(lo <= k && hi >= k) 
    puts("YES");
  else
    puts("NO");
}