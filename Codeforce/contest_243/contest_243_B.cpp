#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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
	cin >> n >> m;
	vector<vector<int> > example_matrix(401, vector<int>(101, -1));
	for (int i = 1; i <=n; i++){
		for (int j = 1; j <=m; j++){
			cin >> example_matrix[i][j];
		}
	}
	for (int k = 1; k <=n; k++){
		vector<vector<int> > temp_matrix(401, vector<int>(101, -1));
		for (int i = 1; i <=k; i++)
			temp_matrix[i] = example_matrix[i];
		int rows = k * 2;
		while (rows <= n){
			int idx = 1; 
			for (int i = rows; i >= (rows / 2) + 1; i--)
				temp_matrix[i] = temp_matrix[idx++];
			rows *= 2;
		}
		if (temp_matrix == example_matrix){
			cout << k << endl;
			return 0;
		}
	}
}