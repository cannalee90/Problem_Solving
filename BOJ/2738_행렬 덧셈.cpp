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


int n, m, k;
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int h, w;
	cin >> h >> w;

	vector<vector<int> > matrix(h, vector<int>(w, 0));

	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			int t1; 
			cin >> t1;
			matrix[i][j] += t1;
		}
	}
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}
