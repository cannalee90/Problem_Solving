//
// Created by  이강호 on 2016. 1. 28..
//

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

struct SCC {
    int n;
    vector<vector<int> > graph;
    vector<vector<int> > rgraph;
    vector<vector<int> > compress;
    vector<int> sccIdx;
    stack<int> st;

    SCC(int size) {
        this->n = size;
        graph.resize(n);
        rgraph.resize(n);
        sccIdx.resize(n, -1);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    void dfs(int here, vector<bool> &visited) {
        visited[here] = true;
        for(int next: graph[here]) {
            if(!visited[next])
                dfs(next, visited);
        }
        st.push(here);
    }

    void rdfs(int here, vector<bool> &visited, vector<int> &path) {
        visited[here] = true;
        path.push_back(here);
        for(int next: rgraph[here]) {
            if(!visited[next]) {
                rdfs(next, visited, path);
            }
        }
    }

    vector<vector<int> > process() {
        vector<bool> visited(n, false);
        vector<bool> rvisited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                dfs(i, visited);
        }
        while(!st.empty()) {
            int here = st.top();
            st.pop();
            if (!rvisited[here]) {
                vector<int> path;
                rdfs(here, rvisited, path);
                for(int v : path) {
                    sccIdx[v] = compress.size();
                }
                compress.push_back(path);
            }
        }
        return compress;
    }
    vector<int> getSCC() {
        return sccIdx;
    }
    int getSize() {
        return compress.size();
    }
    vector<vector<int> > getCompress() {
        vector<vector<int> > cgraph(compress.size());
        for(int i = 0;i < n; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                int here = sccIdx[i];
                int there = sccIdx[graph[i][j]];
                if(here == there) continue;
                cgraph[here].push_back(there);
            }
        }
        for(int i = 0; i < compress.size(); i++) {
            sort(cgraph[i].begin(), cgraph[i].end());
            cgraph[i].erase(unique(cgraph[i].begin(), cgraph[i].end()), cgraph[i].end());
        }
        return cgraph;
    }
    vector<vector<int> > getGraph() {
        return graph;
    }
};

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        SCC scc(n);
        for(int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for(int j = 0; j < n; j++) {
                if(str[j] == '1' && i != j)
                    scc.add_edge(i, j);
            }
        }
        auto compress = scc.process();
        auto cgraph = scc.getCompress(); //get compressed graph
        vector<pair<int, int > > vp; //answer
        vector<vector<int> > matrix(compress.size(), vector<int>(compress.size(), 0));

        for(int i = 0; i < cgraph.size(); i++) {
            for(int next : cgraph[i]) {
                matrix[i][next] = 1;
            }
        }
        //construct compressed matrix

        for(int i = 0; i < compress.size(); i++) {
            if(compress[i].size() == 1) continue;
            vp.push_back({compress[i].back(), compress[i].front()});
            for (int j = 0; j < compress[i].size() - 1; j++) {
                vp.push_back({compress[i][j], compress[i][j + 1]});
            }
        }
        //같은 컴포넌트 안에서 처리하기

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                bool isOnly = true;
                if(matrix[i][j] == 0) continue;
                for(int k = i; k < matrix.size(); k++) {
                    if(matrix[i][k] == 1 && matrix[k][j] == 1)
                        isOnly = false;
                }
                if(isOnly)
                    vp.push_back({compress[i].front(), compress[j].front()});
            }
        }
        //다른 컴포넌트일때 matrix[i][j]를 연결할때는 matrix[i][k] -> matrix[k][j]가 성립하지 않을때만
        //간선을 추가해야 한다. O(n ^ 3)으로 처리 가능.

        printf("%d\n", vp.size());
        for(int i = 0; i < vp.size(); i++) {
            printf("%d %d\n", vp[i].first + 1, vp[i].second + 1);
        }
        puts("");
    }
}
