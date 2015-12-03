#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define INF 987654321

using namespace std;

int main() {
    int n, m;
    int floyd[600][600] = {};
    cin >> n >> m;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j<=n; j++) {
            floyd[i][j] = INF;
        }
        floyd[i][i] = 0;
    }
    for(int i= 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        floyd[u][v] = min(floyd[u][v], c);;
        
    }
    bool isReach = true;
    for(int k = 1; k<=n; k++) {
        for(int i = 1; i<=n; i++) {
            for(int j =1 ; j<= n;j++) {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                if(i == j && floyd[i][j] < 0)
                    isReach = false;
            }
        }
    }
    if(!isReach)
        cout << "-1"<< endl;
    else{
        for(int i = 2; i<=n; i++) {
            if(floyd[1][i] >= 10000 * (n - 1))
                cout << "-1" << endl;
            else
                cout << floyd[1][i] << endl;
        }
    }
}
