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

long long get_multi(int h, int w, vector<int> &arr_1, vector<vector<int> > &arr_2){
	long long ssum = 0;
	for (int i = 0; i < arr_1.size(); i++){
		ssum += arr_1[i] * arr_2[i][w];
	}
	return ssum;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int h_1, w_1;
	int h_2, w_2;
	cin >> h_1 >> w_1;
	vector<vector<int> > arr_1(h_1, vector<int>(w_1, 0));
	for (int i = 0; i < h_1; i++){
		for (int j = 0; j < w_1; j++){
			cin >> arr_1[i][j];
		}
	}
	cin >> h_2 >> w_2;
	vector<vector<int> > arr_2(h_2, vector<int>(w_2, 0));

	for (int i = 0; i < h_2; i++){
		for (int j = 0; j < w_2; j++){
			cin >> arr_2[i][j];
		}
	}
	for (int i = 0; i < h_1; i++){
		for (int j = 0; j < w_2; j++){
			cout << get_multi(i, j, arr_1[i], arr_2) << " ";
		}
		cout << endl;
	}
}