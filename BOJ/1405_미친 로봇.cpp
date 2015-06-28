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
double proba[4];
double ans = 0;
bool board[100][100];
int mmove[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

void sol(int length, int h, int w, double p){
	if (length == n) return;
	for (int i = 0; i < 4; i++){
		int nexth = h + mmove[i][0];
		int nextw = w + mmove[i][1];
		if (!board[nexth][nextw]){
			board[nexth][nextw] = true;
			sol(length + 1, nexth, nextw, p * proba[i]);
			board[nexth][nextw] = false;
		}
		else
			ans += p * proba[i];
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i < 4; i++){
		cin >> proba[i];
		proba[i] /= (double)100;
	}
	board[20][20] = true;
	sol(0, 20, 20, 1);
	printf("%.10lf\n", 1 - ans);
}