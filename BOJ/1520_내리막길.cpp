#include <iostream>
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

int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
vector<vector<long> > ground;
vector < vector<bool> >  visited;
int ans;
int height;
int width;

bool isPossible(int h, int w, long long latitude){
	if (h >= height || w >= width || h < 0 || w < 0)
		return false;
	if (latitude >= ground[h][w])
		return false;
	return true;
}


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> height >> width;
	ground.resize(height + 1, vector<long>(width + 1));
	visited.resize(height + 1, vector<bool>(width + 1));
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			cin >> ground[i][j];
		}
	}
	vector<vector<int> > visited(height + 1, vector<int>(width + 1));
	visited[0][0] = 1;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){

			for (int k = 0; k < 4; k++){
				if (isPossible(i + mmove[k][0], j + mmove[k][1], ground[i][j])){
					visited[i][j] += visited[i + mmove[k][0]][j + mmove[k][1]];
				}
			}
		}
	}

	while (1){
		vector<vector<int > > DP = visited;
		visited.clear();
		visited.resize(height + 1, vector<int>(width + 1, 0));
		visited[0][0] = 1;

		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){

				for (int k = 0; k < 4; k++){
					if (isPossible(i + mmove[k][0], j + mmove[k][1], ground[i][j])){
						visited[i][j] += DP[i + mmove[k][0]][j + mmove[k][1]];
					}
				}
			}
		}
		if (DP == visited)
			break;
	}
	cout << visited[height - 1][width - 1] << endl;
}