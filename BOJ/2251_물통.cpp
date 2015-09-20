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

struct bucket{
  int a,b,c;
  bucket(int a, int, int c) : a(a), b(b), c(c) 
  {}
};

bool visited[201][201][201];
int a, b,c;

int main()
{
  freopen("../input.txt", "r", stdin);
  int send;
  int rest;
  cin >> a >> b >> c;
  queue<bucket> que;
  que.push(bucket(0, 0, c));
  while(!que.empty()) {
    bucket here = que.front();
    que.pop();
    cout << here.a << " "<< here.b << " "<<here.c << endl;
    if(here.a != 0) {
      send = min(here.b + a, b);
      rest = here.a - send;
      cout << "a" << endl;
      if(!visited[rest][send][here.c])
        que.push(bucket(rest, send, c));

      send = min(here.c + a, c);
      rest = here.a - send;

      if(!visited[rest][here.b][send])
        que.push(bucket(rest,here.b,send));
      
    }
    if(here.b != 0) {
      send = min(here.a + b, a);
      rest = here.b - send;      
      cout << "b" << endl;
      if(!visited[send][rest][here.c])
        que.push(bucket(send,rest,here.c));

      send = min(here.c + b, c);
      rest = here.b - send;

      if(!visited[here.a][rest][send])
        que.push(bucket(here.a,rest,send));
    }
    if(here.c != 0) {
      send = min(here.a + c, a);
      rest = here.c - send;
      cout << "c" << endl;
      if(!visited[send][here.b][rest])
        que.push(bucket(send, here.b, rest));

      
      send = min(here.b + c, b);
      rest = here.c - send;

      if(!visited[here.a][send][rest])
        que.push(bucket(here.a, send, rest));
    }
  }
  int ans = 0;
  for(int i = 0; i <= 200; i++) 
    for(int j = 0; j <= 200; j++) 
      if(visited[0][i][j])
        ans++;
  cout << ans << endl;
}