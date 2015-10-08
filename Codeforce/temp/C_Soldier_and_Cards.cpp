#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, t1, t2;
	cin >> n >> t1;
	set<pair<deque<int>, deque<int> > > visited;
	pair<deque<int> , deque<int> > pd;
	for (int i = 0; i < t1; i++){
		int temp;
		cin >> temp;
		pd.first.push_back(temp);
	}
	cin >> t2;
	for (int i = 0; i < t2; i++){
		int temp;
		cin >> temp;
		pd.second.push_back(temp);
	}
	visited.insert(pd);
	int ans = 0;
	int ansp;
	bool isDone = false;
	while (1){
		ans++;
		t1 = pd.first.front();
		t2 = pd.second.front();
		pd.first.pop_front();
		pd.second.pop_front();
		if (t1 > t2){
			pd.first.push_back(t2);
			pd.first.push_back(t1);
		}
		else{
			pd.second.push_back(t1);
			pd.second.push_back(t2);
		}
		if (visited.count(pd))
			break;
		else
			visited.insert(pd);
		if (pd.first.size() == 0 || pd.second.size() == 0){
			if (pd.first.size() == 0) ansp = 2;
			else ansp = 1;
			isDone = true;
			break;
		}
	}
	if (isDone) cout << ans << " " << ansp << endl;
	else cout << "-1" << endl;
}