#
include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include<limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int height;
int width;
vector<vector<int > > ground;
vector<vector<int > > visited;

class data{
public:
	int height;
	int width;
	int direction;
	int count;
	data(int h, int w, int d, int c){
		this->height = h;
		this->width = w;
		this->direction = d;
		this->count = c;
	}
};

inline bool operator<(const data& a, const data& b){
	return a.count < b.count;
}


priority_queue <data, vector<data> > pq;


int mmove[5][2] = { { 0, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

bool isPossible(int h, int w){
	if (h > height || w > width || h < 1 || w < 1) return 0;
	if (ground[h][w] == 1) return 0;
	return 1;
}

int rotate(int direction, int i){
	if (direction == 1){
		if (i == 1) return 0;
		if (i == 2) return 2;
		if (i == 3) return 1;
		if (i == 4) return 1;
	}
	if (direction == 2){
		if (i == 1) return 2;
		if (i == 2) return 0;
		if (i == 3) return 1;
		if (i == 4) return 1;
	}
	if (direction == 3){
		if (i == 1) return 1;
		if (i == 2) return 1;
		if (i == 3) return 0;
		if (i == 4) return 2;
	}
	if (direction == 4){
		if (i == 1) return 1;
		if (i == 2) return 1;
		if (i == 3) return 2;
		if (i == 4) return 0;
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif


	cin >> height >> width;
	ground.resize(height + 1, vector<int>(width + 1));
	visited.resize(height + 1, vector<int>(width + 1));

	for (int i = 1; i <= height; i++){
		for (int j = 1; j <= width; j++){
			cin >> ground[i][j];
			visited[i][j] = INT_MAX;
		}
	}

	int begin_height;
	int begin_width;
	int begin_direction;
	int last_height;
	int last_width;
	int last_direction;
	cin >> begin_height >> begin_width >> begin_direction;
	cin >> last_height >> last_width >> last_direction;

	pq.push(data(begin_height, begin_width, begin_direction, 0));
	visited[begin_height][begin_width] = 0;

	int mmin = INT_MAX;
	int mmin_direction = begin_direction;


	while (!pq.empty()){
		int here_height = pq.top().height;
		int here_width = pq.top().width;
		int here_count = pq.top().count;
		int here_direc = pq.top().direction;
		pq.pop();
		if (visited[here_height][here_width] < here_count)
			continue;
		for (int i = 1; i <= 4; i++){
			for (int j = 1; j <= 3; j++){
				int h = here_height + (mmove[i][0] * j);
				int w = here_width + (mmove[i][1] * j);
				int addition = rotate(here_direc, i);
				if (isPossible(h, w)){
					if (visited[h][w] > here_count + addition + 1){
						visited[h][w] = here_count + addition + 1;
						pq.push(data(h, w, i, here_count + addition + 1));
						if (h == last_height && w == last_width && mmin > here_count + addition + 1 && mmin > here_count + addition + 1) {
							mmin = here_count + addition + 1;
							mmin_direction = i;
						}
					}
				}
				else
					break;
			}
		}
	}
	cout << visited[last_height][last_width] + rotate(mmin_direction, last_direction)<< endl;
}