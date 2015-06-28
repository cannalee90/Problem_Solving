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

ll pig[1000][10];
int test;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> test;
	while (test--){
		ll temp = 0, day = 1, n = 6, m;
		cin >> m;
		memset(pig, 0, sizeof(pig));
		for (int i = 0; i < n; i++){
			cin >> pig[day][i];
			temp += pig[day][i];
		}
		if (temp > m){
			cout << day << endl;
			continue;
		}
		while (true){
			temp = 0;
			day++;
			for (int i = 0; i < n; i++){
				int next, pre;
				if (i == 5) next = 0;
				else next = i + 1;
				if (i == 0) pre = 5;
				else pre = i - 1;
				pig[day][i] = pig[day - 1][i] + pig[day - 1][pre] + pig[day - 1][next] + pig[day - 1][(i + 3) % 6];
				temp += pig[day][i];
			}
			if (temp > m){
				cout << day << endl;
				break;
			}
		}
	}
}