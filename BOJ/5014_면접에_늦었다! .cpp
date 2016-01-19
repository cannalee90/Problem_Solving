//
// Created by  이강호 on 2016. 1. 19..
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r" , stdin);
    int s, g, f, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<int> que;
    vector<int> visited(f + 1, 987654321);
    que.push(s);
    visited[s] = 0;
    while(!que.empty()){
        int here = que.front();
        que.pop();
        for(int i = 0; i < 2; i++){
            int next = (i == 0) ? here + u : here - d;
            if(next > 0 && next <= f && visited[next] > visited[here] + 1){
                visited[next] = visited[here] + 1;
                que.push(next);
            }
        }
    }
    if(visited[g] == 987654321)
        cout << "use the stairs" << endl;
    else
        cout << visited[g] << endl;
    return 0;
}