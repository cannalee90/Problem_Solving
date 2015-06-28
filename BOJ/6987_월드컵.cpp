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

int score[6][6];
bool ans[4];
int result[4][6][3];
int temp[6][3];
bool isSame(int idx){
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 3; j++){
			if (temp[i][j] != result[idx][i][j]) return false;
		}
	}
	return true;
}

void brute_force(int team1, int team2){
	if (team1 == 5 && team2 == 6){
		for (int i = 0; i < 4; i++){
			if (isSame(i)){
				ans[i] = true;
			}
		}
		return;
	}
	for (int k = 1; k <= 3; k++){
		int nextT1 = team1, nextT2 = team2 + 1;
		if (team2 == 5) {
			nextT1++;
			nextT2 = nextT1 + 1;
		}
		score[team1][team2] = k;
		if (k == 1){
			temp[team1][0]++;
			temp[team2][2]++;

		}
		if (k == 2){
			temp[team1][2]++;
			temp[team2][0]++;

		}
		if (k == 3){
			temp[team1][1]++;
			temp[team2][1]++;
		}
		brute_force(nextT1, nextT2);
		score[team1][team2] = 0;
		if (k == 1){
			temp[team1][0]--;
			temp[team2][2]--;

		}
		if (k == 2){
			temp[team1][2]--;
			temp[team2][0]--;

		}
		if (k == 3){
			temp[team1][1]--;
			temp[team2][1]--;
		}

	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	for (int t = 0; t < 4; t++){
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 3; j++){
				cin >> result[t][i][j];
			}
		}
	}
	brute_force(0, 1);
	for (int i = 0; i < 4; i++){
		if (ans[i])
			cout << "1 ";
		else
			cout << "0 ";
	}
	cout << endl;
}