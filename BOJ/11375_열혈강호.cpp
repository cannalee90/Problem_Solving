#include <iostream>
#include <vector>

using namespace std;

vector<int> emp;
vector<int> work;
vector<vector<int> > graph;
vector<int> check;

bool dfs(int here) {
  for(int i = 0; i < graph[here].size(); i++) {
    int there = graph[here][i];
    if(check[there]) continue;
    check[there] = true;
    if(work[there] == -1 || dfs(work[there])) {
      work[there] = here;
      return true;
    }
  }
  return false;
}

int main() {
  freopen("input.txt", "r+", stdin);
  int n, m;
  cin >> n >> m;
  emp.assign(n + 1, 0);
  work.assign(m + 1, -1);
  graph.assign(n + 1, vector<int>(0));
  for(int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    for(int j = 0; j < tmp; j++) {
      int num;
      cin >> num;
      graph[i].push_back(num);
    }
  }
  
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    check.assign(m + 1, false);
    if(dfs(i)) 
      ans++;
  }
  cout << ans << endl;
}
