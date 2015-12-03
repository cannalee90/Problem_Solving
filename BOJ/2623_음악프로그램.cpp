#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>

#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n + 1);
    vector<int> indegree(n + 1);
    for(int i = 0; i < m; i++) {
        int q;
        int u = -1, v;
        cin >> q;
        while(q--) {
            cin >> v;
            if(u != -1) {
                graph[u].push_back(v);
                indegree[v]++;
            }
            u = v;
        }
    }
    vector<int> ans;
    vector<bool> check(n + 1, false);
    for(int i = 0; i < n; i++) {
        bool isDelete = false;
        for(int j = 1; j <= n; j++) {
            if(!indegree[j] && !check[j]) {
                ans.push_back(j);
                for(int k = 0; k < graph[j].size(); k++)
                    indegree[graph[j][k]]--;
                isDelete = true;
                check[j] = true;
                break;
            }
        }
        if(!isDelete) {
            cout << "0" << endl;
            exit(0);
        }
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}
