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

int ans, cnt = 0;
vector<bool > isCut;

int dfs(vector<vector<int> > &graph, vector<int> &discovery, int here, bool isRoot) {

	discovery[here] = ++cnt;

	int ret = discovery[here];
	int children = 0;

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		int mmin = discovery[there];
		//현재 정점을 루트로 해서 각각의 서브트리에서 가장 높이 갈 수 있는 정점의 번호를 찾아서 리턴한다
		//만약 현재 서브트리와 연결되어있는 가장 숫자가 작은 조상(높은 조상)이 현재의 정점보다 적다면 이는 
		//이정점이 Cutvertex인걸 의미한다.
		if (discovery[there] == 987654321) {
			children++;
			mmin = dfs(graph, discovery, there, false);
			if (mmin >= discovery[here] && !isRoot && isCut[here] == false) {
				isCut[here] = true;
				ans++;
			}
			ret = min(ret, mmin);
		}
		else
			ret = min(ret, discovery[there]);
	}

	//만약 이 정점이 루트이면 절단점의 조건은 자식을 두개 이상 가져야 한다. 이는 그림을 그려보면 자명함
	if ((isRoot && children >= 2)){
		isCut[here] = true;
		ans++;
	}

	return ret;
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n){
		if (n == 0) exit(0);
		vector<vector<int> > graph(n + 1); //그래프 
		vector<int > discovery(n + 1, 987654321); //간선의 분류를 위한 배열
		isCut = vector<bool>(n + 1, false);	 //정점이 절단점인지 아닌지 확인하기 위한

		string str;

		//그래프 모델링

		while (getline(cin, str)) {
			if (str.size() == 1 && str[0] == '0')
				break;
			else {
				int num = 0;
				bool ishere = false;
				int here;
				str.push_back(' ');
				for (int i = 0; i < str.size(); i++) {
					if (str[i] == ' ') {
						if (ishere) {
							graph[here].push_back(num);
							graph[num].push_back(here);
							num = 0;
						}
						else{
							here = num;
							num = 0;
							ishere = true;
						}
					}
					else {
						num *= 10;
						num += str[i] - '0';
					}
				}

			}
		}

		cnt = 0;
		ans = 0;
		for (int i = 1; i <= n; i++){
			if (discovery[i] == 987654321)
				dfs(graph, discovery, 1, true);
		}
		cout << ans << endl;
	}
}