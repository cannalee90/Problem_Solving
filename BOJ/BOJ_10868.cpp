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
#include <time.h>

typedef long long ll;
using namespace std;

#define pb push_back
#define mp(a, b) make_pair((a), (b));

int get_idx(int p) {
  int idx = 1;
  while(idx < p)
    idx *= 2;
  return idx;
}

ll get_sum(vector<ll> &tree, int left, int right) {
  ll mmin = 9876543210;
  while(left <= right){
    if(left % 2 == 1)
      mmin = min(tree[left++], mmin);
    if(right % 2 == 0)
      mmin = min(tree[right--], mmin);
    left /= 2;
    right /= 2;
  }
  return mmin;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int n, m;
  scanf("%d %d", &n, &m);
  int idx = get_idx(n);
  
  vector<ll> vl(idx * 2, 987654321);
  

  for(int i = 0; i < n; i++) 
    scanf("%lld", &vl[idx + i]);
  idx /= 2;

  while(idx) {
    for(int i = 0; i < idx; i++) 
      vl[idx + i] = min(vl[(idx + i) * 2] , vl[(idx + i ) * 2 + 1]);
    idx/=2;
  }

  idx = get_idx(n);
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", get_sum(vl, a + idx - 1, b + idx - 1));
  }
}