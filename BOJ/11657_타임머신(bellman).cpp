#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>
using namespace std;
typedef pair<int,int> pi;

vector<pi> graph[505];
int dist[505];

#define INF 987654321

void solve(){
    int n,m;
    vector<int> dist(505, INF);
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        graph[x].push_back(make_pair(y, z));
    }
    int upd = 0;
    dist[1] = 0;
    for (int i=0; i<n; i++) {
        upd = 0;
        for (int j=1; j<=n; j++) {
            for (auto &k : graph[j]){
                if(dist[k.first] > dist[j] + k.second){
                    upd = 1;
                    dist[k.first] = dist[j] + k.second;
                }
            }
        }
        if(upd == 0) break;
    }
    if(upd != 0)
        cout << "-1" << endl;
    else {
        for(int i = 2; i<=n; i++){
            if(dist[i] > (n - 1) * 10000)
                cout << "-1" << endl;
            else
                cout << dist[i] << endl;
        }
        
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    solve();
}