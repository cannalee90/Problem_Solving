#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
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

using namespace std;
typedef long long ll;

char maze[50][50][50];
int visited[50][50][50];
int k, h, w;
int mmove[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, -1 }, { 0, 0, 1 } };

class node{
public:
	int dis;
	int z;
	int h;
	int w;
	bool operator>(const node & a)const{
		return dis > a.dis;
	}
	node(){
		this->dis = 0;
		this->z = 0;
		this->w = 0;
		this->h = 0;
	}
};

bool isPossible(int cost, int tz, int th, int tw){
	if (tz >= k || tz < 0 || th >= h || th < 0 || tw >= w || tw < 0) return 0;
	if (maze[tz][th][tw] == '#') return 0;
	if (visited[tz][th][tw] <= cost) return 0;
	return 1;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while (cin >> k >> h >> w){
		if (k == 0 && h == 0 && w == 0) return 0;
		int bw, bh, bz, ew, eh, ez;
		memset(maze, 0, sizeof(maze));
		for (int i = 0; i < k; i++){
			for (int j = 0; j < h; j++){
				for (int p = 0; p < w; p++){
					cin >> maze[i][j][p];
					if (maze[i][j][p] == 'S') bz = i, bh = j, bw = p;
					if (maze[i][j][p] == 'E') ez = i, eh = j, ew = p;
					visited[i][j][p] = INT_MAX;
				}
			}
		}
		priority_queue<node, vector<node>, greater<node> > pq;
		node temp, here;
		temp.dis = 0; temp.w = bw; temp.z = bz; temp.h = bh;
		pq.push(temp);
		while (!pq.empty()){
			here = pq.top();
			pq.pop();
			//if (visited[here.z][here.w][here.h] < here.dis) continue;

			for (int i = 0; i < 6; i++){
				if (isPossible(here.dis + 1, here.z + mmove[i][0], here.h + mmove[i][1], here.w + mmove[i][2])){
					temp.dis = here.dis + 1;
					temp.z = here.z + mmove[i][0];
					temp.h = here.h + mmove[i][1];
					temp.w = here.w + mmove[i][2];
					pq.push(temp);
					visited[here.z + mmove[i][0]][here.h + mmove[i][1]][here.w + mmove[i][2]] = here.dis + 1;
				}
			}
		}
		if (visited[ez][eh][ew] == INT_MAX) cout << "Trapped!" << endl;
		else printf("Escaped in %d minute(s).\n", visited[ez][eh][ew]);
	}
}