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

int main()
{
  freopen("../input.txt", "r", stdin);
  
  int n;
  priority_queue<int, vector<int> , greater<int> > a, c;
  priority_queue<int, vector<int> , less<int> > b, d;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int t1, t2;
    cin >> t1 >> t2;
    
    a.push(t1);
    b.push(t2);
    c.push(t2);
    d.push(t1);
    cout << max(a.top() + b.top(), c.top() + d.top()) << endl;
  } 
}