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

int get_idx(int p) {
  int idx = 1;
  while(idx < p) idx *= 2;
  return idx;
}

void update(vector<int> &tree, int idx, int val) {
  tree[idx] += val;
  idx /= 2;
  while(idx) {
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    idx /= 2;
  }
}

ll get_answer(vector<int> &tree, int here) {
  int node = 1;

  while(node < tree.size() / 2) {

    if(tree[node * 2] >= here) {
      node = node * 2;
    }else {
      here -= tree[node * 2];
      node = node * 2 + 1;
    }
  }
  
  return node - (tree.size() / 2);
}

int main() {
  freopen("../input.txt", "r", stdin);
  int n, k;
  cin >> n >> k;

  int idx = get_idx(n);
  vector<int> tree(idx * 2, 0);

  for(int i = idx; i < idx * 2; i++) 
    update(tree, i, 1);

  int here = k;
  cout << "<";
  for(int i = n; i >= 1; i--) {
    here %= i;
    if(!here)
      here = i;
    int ans = get_answer(tree, here);
    if(i != 1)
      cout << ans  << ", ";
    else
      cout << ans << ">" << endl;    

    update(tree, ans + idx - 1, -1);
    here += (k -1);
  }
  cout << tree[1] << endl;



}


