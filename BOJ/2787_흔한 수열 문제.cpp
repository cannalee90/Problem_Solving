#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define INF 987654321

using namespace std;

bool dfs(vector<vector<int> >& graph, vector<int>& match, vector<bool>& check, int here) {
    for(int next : graph[here]) {
        if(check[next]) continue;
        check[next] = true;
        if(match[next] == -1 || dfs(graph, match, check, match[next])) {
            match[next] = here;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    vector<pair<int, int > > vp(n + 1, pair<int, int >(n, 1));
    vector<int> position_min(n + 1, 1);
    vector<int> position_max(n + 1, n);
    for(int i = 0; i < m; i++) {
        int q, a, b, v;
        scanf("%d %d %d %d", &q, &a, &b, &v);
        if(q == 1) {
            for(int j = a; j<= b; j++) {
                vp[j].first = min(vp[j].first, v);
            }
        }
        else if(q == 2){
            for(int j = a; j<= b; j++) {
                vp[j].second = max(vp[j].second, v);
            }
        }
        position_max[v] = min(position_max[v], b);
        position_min[v] = max(position_min[v], a);
    }
    //불가능한 경우를 생각하고 maxflow를 돌리면 된다. graph(v, u)는 v와 u가 매칭될 수 있다는 뜻.
    //하지만 이렇게 될 경우 반드시 들어가야한다..라는 조건이 성립되지 않는다. 그래서
    //각각의 숫자에 대해서 max와 min값을 한번씩 더 정해준다. position_min과 max가 그 내용..
    vector<vector<int > > graph(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i >= position_min[j] && i <= position_max[j] && j >= vp[i].second && j <= vp[i].first)
                graph[i].push_back(j);
        }
    }
    vector<int> match(n + 1, -1);
    vector<bool> check(n + 1, false);
    int ans = 0;
    for(int i = 1; i<= n; i++) {
        fill(check.begin(), check.end(), false);
        if(dfs(graph, match, check, i))
            ans++;
    }
    if(ans != n)
        cout << "-1" << endl;
    else{
        vector<int> output(n + 1);
        for(int i = 1; i<= n; i++)
            output[match[i]] = i;
        for(int i = 1; i <=n; i++)
            cout << output[i] << " ";
    }
}
