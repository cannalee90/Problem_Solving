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

using namespace std;
typedef long long ll;

int m;
bool visited[11][1000000];

int swap(int num, int i, int j){

	int a = (num % (int)pow(10, i + 1)) / ((int)pow(10, i));
	int b = (num % (int)pow(10, j + 1)) / ((int)pow(10, j));
	num -= a * pow(10, i);
	num -= b * pow(10, j);
	num += a * pow(10, j);
	num += b * pow(10, i);
	if (num < pow(10, m - 1)) return -1;
	return num;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	cin >> n;
	cin >> k;
	if (n == 1000000){
		cout << "1000000" << endl;
		return 0;
	}
	m = (to_string(n)).size();
	queue<pair<int, int > > que;
	que.push(make_pair(0, n));
	int mmax = 0;
	while (!que.empty()){
		int here = que.front().second;
		int cost = que.front().first;
		que.pop();
		for (int i = 0; i < m; i++){
			for (int j = i + 1; j < m; j++){
				int num = swap(here, i, j);
				if (num == -1) continue;
				if (!visited[cost + 1][num]){
					if (cost + 1 < k){
						que.push(make_pair(cost + 1, num));
						visited[cost + 1][num] = true;
					}
					else{
						mmax = max(mmax, num);
					}
				}
			}
		}
	}
	if (mmax == 0) cout << "-1" << endl;
	else cout << mmax << endl;
