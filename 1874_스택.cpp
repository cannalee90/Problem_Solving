#include <iostream>
#include <utility>
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


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int idx = 0;
	string ans;
	vector<int> result;
	stack<int> stack;
	cin >> n;
	for (int i = 0; i < n; i++){
		int t1;
		scanf("%d", &t1);
		result.push_back(t1);
	}
	for (int i = 1; i <= n; i++){
		stack.push(i);
		ans.push_back('+');
		while (!stack.empty() && stack.top() == result[idx]){
			ans.push_back('-');
			stack.pop();
			idx++;
		}

	}
	if (idx != n)
		printf("NO\n");
	else{
		for (int i = 0; i < ans.size(); i++){
			printf("%c\n", ans[i]);
		}
	}
}