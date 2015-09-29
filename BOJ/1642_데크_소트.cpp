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
  int n;
  cin >> n;
  vector<int> data(n);
  set<int> d2;
  for(int &i : data) {
    cin >> i;
    d2.insert(i);
  }
  vector<int> front, back;
  front.push_back(data[0]);
  back.push_back(data[0]);
  for (int i = 1; i < n; i++) {
    int num = data[i];
    bool isFind = false;
    for (int j = 0; j < front.size(); j++) {
      auto cmp = d2.lower_bound(front[j]);
      if (cmp != d2.begin()) {
        if(*(--cmp) == data[i]) {
          front[j] = *cmp;
          isFind = true;
          break;
        }
      }
    }
    for (int j = 0; j < back.size(); j++) {
      auto cmp = d2.lower_bound(back[j]);
      cmp++;
      if (cmp != d2.end()) {
        if(*(cmp) == data[i]) {
          back[j] = *cmp;
          isFind = true;
          break;
        }
      }
    }
    if(!isFind) {
      front.push_back(data[i]);
      back.push_back(data[i]);
    }
  }
  cout << front.size() << endl;
}
