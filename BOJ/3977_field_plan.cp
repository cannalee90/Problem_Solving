#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stack>
#include <map>

#define INF 987654321
typedef long long ll;

using namespace std;

struct SCC {
    int n;
    int vcnt;
    int sccidx;
    vector<bool> check;
    vector<int> discovery;
    vector<vector<int> > graph;
    vector<int> scc;
    stack<int> st;
    
    SCC(int n) {
        vcnt = 0;
        this->n = n;
        sccidx = 0;
        
        check = vector<bool>(n);
        discovery = vector<int>(n, INF);
        graph = vector<vector<int> >(n);
        scc = vector<int>(n, -1);
    }
    
    void calSCC() {
        for(int i = 0; i < n; i++) {
            if(discovery[i] == INF)
                getSCC(i);
        }
    }
    
    int getSCC(int here) {
        //Get SCC
        discovery[here] = ++vcnt;
        int ret = discovery[here];
        st.push(here);
        
        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i];
            if (discovery[there] == INF)
                ret = min(ret, getSCC(there));
            else if (scc[there] == -1)
                ret = min(ret, discovery[there]);
        }
        
        if (ret == discovery[here]) {
            while (true) {
                int t = st.top();
                st.pop();
                scc[t] = sccidx;
                if (t == here)
                    break;
            }
            sccidx++;
        }
        return ret;
    }
    
    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        SCC scc = SCC(n);
        vector<int> check(n);
        for(int i = 0; i < m; i++) {
            int u , v;
            scanf("%d %d", &u, &v);
            scc.add_edge(u, v);
        }
        scc.calSCC();
        vector<vector<int > > sccgraph(scc.sccidx);
        vector<int> indegree(scc.sccidx);
        for (int i = 0; i < n; i++) {
            int u = scc.scc[i];
            for (int j = 0; j < scc.graph[i].size(); j++) {
                int v = scc.scc[scc.graph[i][j]];
                if(u != v) {
                    sccgraph[v].push_back(u);
                    indegree[v]++;
                }
            }
        }
        int p = -1;
        bool isConfused = false;
        for(int i = 0; i < scc.sccidx - 1; i++) {
            if(sccgraph[i].size() == 0){
                isConfused = true;
            }
        }
        if(isConfused) {
            cout << "Confused" << endl;
            //confused 조건은 위상정렬이 불가능할 경우 즉, 마지막 노드가 아니면서 outdegree가 0이 아닐 경우에 발생
        }
        else {
            for(int i = 0; i < scc.sccidx; i++) {
                if(indegree[i] == 0) {
                    p = i;
                    break;
                }
            }
            for(int i = 0; i < n; i++) {
                if(scc.scc[i] == p)
                    cout << i << endl;
            }
        }
        cout << endl;
    }
}

