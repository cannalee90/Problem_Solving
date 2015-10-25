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

#define INF 987654321

typedef long long ll;
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> dis(n, INF);
	vector<int> jump(n);
	for (int i = 0; i < n; i++)
		cin >> jump[i];
	dis[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= jump[i]; j++){
			int next = i + j;
			if (next < n && dis[next] > dis[i] + 1) {
				dis[next] = dis[i] + 1;
			}
		}
	}
	if (dis[n - 1] != INF)
		cout << dis[n - 1] << endl;
	else
		cout << "-1" << endl;
}