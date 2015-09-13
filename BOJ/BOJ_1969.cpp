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

inline bool compare(const pair<int, int > &a, const pair<int, int > &b) {
  if(a.first == b.first)
    return a.second > b.second;
  else
    return a.first < b.first;
}

int main() {
  //freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  string data[1001], ans;

  for(int i = 0; i < n; i++)    
    cin >> data[i];

  for(int i = 0; i < m; i++) {
    vector<pair<int, char > > cmp(4);
    cmp[0].second = 'A';
    cmp[1].second = 'C';
    cmp[2].second = 'G';
    cmp[3].second = 'T' ;   
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < 4; k++) {
        if(data[j][i] == cmp[k].second)
          cmp[k].first ++;
      }
    }
    sort(cmp.begin(), cmp.end(), compare);
    /*for(int i = 0; i < 4; i++)
      cout << cmp[i].second << " " << cmp[i].first << endl;
    puts("");
    */ans.push_back(cmp[3].second);
  }
  cout << ans << endl;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(data[i][j] != ans[j])
        cnt++;
    }
  }
  cout << cnt << endl;
}

