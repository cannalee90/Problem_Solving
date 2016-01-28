#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <climits>


using namespace std;
typedef long long ll;

#define INF 987654321

int getNext(int num, int idx) {
    if(idx == 0) {
        return (num * 2) % 10000;
    }else if(idx == 1) {
        return (num != 0) ? num - 1 : 9999;
    }else if(idx == 2) {
        int left = num / 1000;
        num = (num * 10) % 10000;
        return num + left;
    }else {
        int right = num % 10;
        num /= 10;
        return (right * 1000) + num;
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<bool> visited(10000, false);
        vector<int> parent(10000, -1);
        vector<int> method(10000);
        visited[n] = true;
        queue<int> que;
        que.push(n);
        while(!que.empty() && !visited[m]) {
            int num = que.front();
            que.pop();
            for(int i = 0;i < 4; i++) {
                int next = getNext(num, i);
                if(visited[next] == false) {
                    visited[next] = true;
                    parent[next] = num;
                    method[next] = i;
                    que.push(next);
                }
            }
        }
        string str;
        while(parent[m] != -1) {
            if(method[m] == 0) str.push_back('D');
            else if(method[m] == 1) str.push_back('S');
            else if(method[m] == 2) str.push_back('L');
            else if(method[m] == 3) str.push_back('R');
            m = parent[m];
        }
        reverse(str.begin(), str.end());
        puts(str.c_str());
    }
}
