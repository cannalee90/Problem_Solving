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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	char t1;
	cin >> n >> m;
	vector<vector<char> > ground(n, vector<char>(m, '.'));
	vector<int>meteor_coor(m, INT_MIN );
	vector<vector<char> > meteor(n, vector<char>(m, '.'));
	vector<int>ground_coor(m, n);

	for (int i = 0; i < n; i++){
		getchar();
		for (int j = 0; j < m; j++){
			scanf("%c", &t1);
			if (t1 == 'X'){
				meteor[i][j] = t1;
				meteor_coor[j] = max(meteor_coor[j], i+ 1);
			}
			else if(t1 == '#'){
				ground[i][j] = t1;
				ground_coor[j] = min(ground_coor[j], i);
			}
		}
	}
	int mmin = INT_MAX;
	for (int i = 0; i < m; i++){
		if (meteor_coor[i] != INT_MIN)
			mmin = min(mmin, abs(ground_coor[i] - meteor_coor[i]));
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (meteor[i][j] == 'X')
				ground[i + mmin][j] = 'X';
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%c", ground[i][j]);
		}
		printf("\n");
	}
}
