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
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> data(m);
  set<int> in, uni;

  for(int &i : data) {
    cin >> i;
  }

  for(int i = 0; i < m; i ++) {
    int num = data[i];
    if(in.count(num))
      continue;
    else if(in.size() < n)
      in.insert(num);
    else {
      int val = -1;
      set<int> temp = in;
      for(int j = i + 1; j < data.size(); j++) {
        if(temp.count(data[j])) {
          val = data[j];
          temp.erase(temp.lower_bound(data[j]));
        }
      }
      set<int>::iterator itor;
      if(temp.size() != 0) 
        itor = in.lower_bound(*temp.begin());
      else if (val != -1)
        itor = in.lower_bound(val);
      else
        itor = in.begin();

      in.erase(itor);
      in.insert(num);
      ans ++;
    }
  }
  cout << ans << endl;
}