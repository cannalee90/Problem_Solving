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

vector<long long> data;
vector<long long> tree;

long long n, m, k;
long long mmove[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
long long height;
long long width;


long long get_sum(int y, int x, vector<vector<long long > > &DP){
	long long ssum = 0;
	for (int i = 0; i < 8; i++){
		int h = y + mmove[i][0];
		int w = x + mmove[i][1];
		if (h < 0 || w < 0 || h >= height || w >= width)
			continue;
		else
			ssum += DP[h][w];
	}
	return ssum;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string data;
	int lens;
	cin >> height;
	cin >> width;
	cin >> lens;
	vector<vector<char> > board;
	board.resize(height, vector<char>(width, ' '));
	vector<vector<long long > > DP(height, vector<long long>(width, 0));

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			cin >> board[i][j];
		}
	}
	cin >> data;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (board[i][j] == data[0]){
				DP[i][j] = 1;
			}
		}
	}
	for (long long k = 1; k < data.size(); k++){
		vector<vector<long long > > temp(height, vector<long long>(width, 0));

		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				if (board[i][j] == data[k]){
					temp[i][j] = get_sum(i, j, DP);
				}
			}
		}
		DP = temp;
	}
	long long ans = 0;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			ans += DP[i][j];
		}
	}
	cout << ans << endl;
}
