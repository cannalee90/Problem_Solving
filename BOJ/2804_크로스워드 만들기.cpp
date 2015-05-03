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
	string str1, str2;
	cin >> str1 >> str2;
	int n = str1.size();
	int m = str2.size(); 
	vector<vector<char> > board(m, vector<char>(n, '.'));
	int idx_i = -1;
	int idx_j = -1;
	for (int i = 0; i < n; i++){
		bool isFind = false;
		for (int j = 0; j < m; j++){
			if (str1[i] == str2[j]){
				idx_i = j;
				idx_j = i;
				isFind = true;
				break;
			}
		}
		if (isFind) break;
	}
	for (int i = 0; i < n; i++)
		board[idx_i][i] = str1[i];
	for (int j = 0; j < m; j++)
		board[j][idx_j] = str2[j];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << board[i][j]; 
		}
		cout << endl;
	}
}