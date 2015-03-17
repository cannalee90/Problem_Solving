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

vector<vector<int > > ground;
vector<vector<int > > visited;
int n;

class data{
public:
	int height;
	int width;
	int min;
	int max;
	data(int h, int w, int mmin, int mmax){
		this->height = h;
		this->width = w;
		this->min = mmin;
		this->max = mmax;
	}
};

inline bool operator<(const data& a, const data& b){
	return (a.max - a.min) > (b.max - b.min);
}

int mmove[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

bool isPossible(int h, int w){
	if (h > n || w > n || h < 1 || w < 1) 
		return 0;
	return 1;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	ground.resize(n + 1, vector<int>(n + 1, 0));
	visited.resize(n + 1, vector<int>(n + 1, INT_MAX));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> ground[i][j];
		}
	}

}

