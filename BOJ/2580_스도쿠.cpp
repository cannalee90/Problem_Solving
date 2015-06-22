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

typedef long long ll;
using namespace std;

int n, m, test;
int sudoku[10][10];
bool isMade;
vector<pair<int, int > > dots;

bool isPossible(int idx, int num){
	int hcnt = 0, wcnt = 0, scnt = 0;
	int hcntzero = 0;
	int wcntzero = 0;
	int scntzero = 0;
	int h = dots[idx].first;
	int w = dots[idx].second;
	for (int i = 0; i < 9; i++){
		if (sudoku[h][i] == num) return false;
		if (sudoku[h][i] == 0) hcntzero++;
		else hcnt += sudoku[h][i];
	}
	for (int i = 0; i < 9; i++){
		if (sudoku[i][w] == num) return false;
		if (sudoku[i][w] == 0) wcntzero++;
		else 	wcnt += sudoku[i][w];
	}
	int hl = (h / 3) * 3;
	int wl = (w / 3) * 3;
	for (int i = hl; i < hl + 3; i++){
		for (int j = wl; j < wl + 3; j++){
			if (sudoku[i][j] == num) return false;
			if (sudoku[i][j] == 0)
				scntzero++;
			else
				scnt += sudoku[i][j];
		}
	}
	if (hcntzero == 1){
		if (num == 45 - hcnt) return true;
		else return false;
	}
	if (wcntzero == 1){
		if (num == 45 - wcnt) return true;
		else return false;
	}
	if (scntzero == 1){
		if (num == 45 - scnt) return true;
		else return false;
	}

	return true;
}

void prefill(int idx){
	int hcnt = 0, wcnt = 0, scnt = 0;
	int cntzero = 0;
	int h = dots[idx].first;
	int w = dots[idx].second;
	for (int i = 0; i < 9; i++){
		if (sudoku[h][i] == 0)
			cntzero++;
		else
			hcnt += sudoku[h][i];
	}
	if (cntzero == 1){
		sudoku[h][w] = 45 - hcnt;
		dots.erase(dots.begin() + idx);
		return;
	}
	cntzero = 0;
	for (int i = 0; i < 9; i++){
		if (sudoku[i][w] == 0)
			cntzero++;
		else
			wcnt += sudoku[i][w];
	}
	if (cntzero == 1){
		sudoku[h][w] = 45 - wcnt;
		dots.erase(dots.begin() + idx);

		return;
	}
	cntzero = 0;
	h = (h / 3) * 3;
	w = (w / 3) * 3;
	for (int i = h; i < h + 3; i++){
		for (int j = w; j < w + 3; j++){
			if (sudoku[i][j] == 0)
				cntzero++;
			else
				scnt += sudoku[i][j];
		}
	}
	if (cntzero == 1){
		sudoku[dots[idx].first][dots[idx].second] = 45 - scnt;
		dots.erase(dots.begin() + idx);

		return;
	}
	
}

void su(int cnt ){
	if (isMade) return;
	if (cnt == dots.size()){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				cout << sudoku[i][j];
			}
			cout << endl;
		}
		isMade = true;
		return;
	}
	for (int j = 1; j < 10; j++){
		if (isPossible(cnt, j)){
			sudoku[dots[cnt].first][dots[cnt].second] = j;
			su(cnt + 1);
			sudoku[dots[cnt].first][dots[cnt].second] = 0;
		}
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int cnt = 0;
	char c;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cin >> c;
			sudoku[i][j] = c - '0';
			if (sudoku[i][j] == 0)
				dots.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < dots.size(); i++) prefill(i);
	su(0);
}