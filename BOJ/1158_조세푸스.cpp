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
#include <list>

typedef long long ll;
using namespace std;

int main() {
  freopen("../input.txt", "r", stdin);
  int n, k;
  cin >> n >> k;
  list<int> que;
  for(int i = 1; i <=n; i++) 
    que.push_back(i);

  auto itor = que.begin();  
  cout << "<";

  while(que.size() != 1) {
    int cnt = k - 1;
    while(cnt) {
      while(itor != que.end() && cnt) {
        cnt--;
        itor++;
      }
      if(itor == que.end())
        itor = que.begin();
    }
    cout << *itor << ", ";
    itor = que.erase(itor);
  }
  cout << *que.begin() << ">" << endl;
}