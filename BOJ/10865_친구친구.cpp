#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int > graph(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u]++;
        graph[v]++;
    }
    for(int i = 1; i <= n; i++)
        cout << graph[i] << endl;
}
