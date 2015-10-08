#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

#define INF 987654321


int sccidx;
//SCC COMPONENT의 idx
int cnt;
//간선의 종류를 구분하기 위해서 정점의 발견 순서를 저장한다. 

bool cmp(const vector<int> &a, const vector<int> &b) {
	//출력을 위한 소트
	return a[0] < b[0];
}

int dfs(vector<vector<int> > &graph, vector<int> &dis, vector<int> &SCC, stack<int> &st, int u) {

	dis[u] = ++cnt;
	//간선의 종류를 알아내기위해서 정점의 발견 순서를 기록한다.
	int ret = dis[u];
	//자신의 자식 중에서 자기보다 조상으로 갈 수 있는지 기록하는 변수이다. 초기값은 자기 자신의 번호
	st.push(u);
	//u의 subtree는 모두 u보다 위쪽의 stack 쌓이게 된다.
	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		//there
		int mmin = INF;
		if (dis[v] == INF)
			mmin = dfs(graph, dis, SCC, st, v);
		//mmin을 갱신할  u -> v 가 트리간선일 경우
		else if (SCC[v] == -1)
			mmin = dis[v];
		//혹은 u -> v 교차 간선일때 다른 만약 그 교차간선이 다른 컴포넌트의 정점이지 않을 경우에만 ret을 갱신해야한다.
		//다른 컴포넌트의 정점일 경우 
		ret = min(ret, mmin);

	}


	if (ret == dis[u]) {

		while (true) {
			int t = st.top();
			SCC[st.top()] = sccidx;
			st.pop();
			if (t == u) break;
		}
		sccidx++;
	}

	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;

	vector < vector< int > >  graph(n + 1);
	vector <int> dis(n + 1, INF);
	//정점의 발견 순서를 기록
	vector <int> SCC(n + 1, -1);
	//i번째 정점이 몇번째 component인지 기록한다.
	vector <vector< int > > ans;
	//답 출력을 위한 배열

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		stack<int> st;
		if (dis[i] == INF) //정점이 한번도 발견 되지 않았을 때에만 탐색을 시작한다.
			dfs(graph, dis, SCC, st, i);
	}

	ans.resize(sccidx);

	for (int i = 1; i <= n; i++) {
		int sccid = SCC[i];
		ans[sccid].push_back(i);
	}

	for (int i = 0; i < ans.size(); i++) {
		sort(ans[i].begin(), ans[i].end());
	}

	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "-1\n";
	}
}

