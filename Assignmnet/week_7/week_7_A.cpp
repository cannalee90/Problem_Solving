#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
char map[600][600];
int n;

bool Ispossible(int height, int width, int idx)
{
	height += mmove[idx][0], width += mmove[idx][1];
	if (height < 0 || width < 0 || height >= n || width >= n || map[height][width] == '0') return 0;
	return 1;
}


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	std::ios::sync_with_stdio(false);
	while (t--){
		char t1;
		cin >> n;
		vector<int> result;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (map[i][j] == '1'){
					queue <pair<int, int> > que;
					que.push(make_pair(i, j));
					int block = 1;
					map[i][j] = '0';
					while (!que.empty()){
						int height = que.front().first, width = que.front().second;
						que.pop();
						for (int k = 0; k < 4; k++){
							if (Ispossible(height, width, k)){
								block++;
								que.push(make_pair(height + mmove[k][0], width + mmove[k][1]));
								map[height + mmove[k][0]][width + mmove[k][1]] = '0';
							}
						}
					}
					result.push_back(block);
				}
			}
		}
		cout << *max_element(result.begin(), result.end()) << endl;
	}
}