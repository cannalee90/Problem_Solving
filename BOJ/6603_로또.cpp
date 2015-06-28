#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
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

int n, m, test;
vector<int> num;
vector<bool> visited;

void brute_force(int pos, int cnt){
	if (pos == n && cnt == 6){
		for (int i = 0; i < n; i++){
			if (visited[i]) printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	if (pos == n) return;
	visited[pos] = true;
	brute_force(pos + 1, cnt + 1);
	visited[pos] = false;
	brute_force(pos + 1, cnt);
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while (true){
		cin >> n;
		if (n == 0) return 0;
		num = vector<int>(n);
		visited = vector<bool>(n);
		for (int i = 0; i < n; i++) cin >> num[i];
		brute_force(0, 0);
		printf("\n");
	}
}