#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int width, height;
vector<vector< char > > board;
vector<vector< int > > counting;

int mmove[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

class data{
public:
	int h;
	int w;
	int cnt;
	data(int h, int w, int cnt){
		this->h = h;
		this->w = w;
		this->cnt = cnt;
	}
};

inline bool operator<(const data& a, const data& b)
{
	return a.cnt < b.cnt;
}

bool isPossible(int h, int w, int cnt, int i){
	h += mmove[i][0];
	w += mmove[i][1];
	if (h >= height || w >= width || h < 0 || w < 0) return 0;
	if (counting[h][w] < cnt + 1)  return 0;
	return 1;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> width >> height;

	board.resize(height + 1, vector<char>(width + 1, '0'));
	counting.resize(height + 1, vector<int>(width + 1, INT_MAX));

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			cin >> board[i][j];
		}
	}

	priority_queue< data, vector<data> > pq;
	pq.push(data(0, 0, 0));

	while (!pq.empty()){
		int h = pq.top().h;
		int w = pq.top().w;
		int cnt = pq.top().cnt;
		pq.pop();
		for (int i = 0; i < 4; i++){
			if (isPossible(h, w, cnt, i)){
				if (board[h + mmove[i][0]][w + mmove[i][1]] == '1')
				{
					pq.push(data(h + mmove[i][0], w + mmove[i][1], cnt + 1));
					counting[h + mmove[i][0]][w + mmove[i][1]] = cnt + 1;
				}
				else
				{
					pq.push(data(h + mmove[i][0], w + mmove[i][1], cnt));
					counting[h + mmove[i][0]][w + mmove[i][1]] = cnt;
				}
			}
		}
	}
	cout << counting[height - 1][width - 1] << endl;
}


