#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int get_score(double x, double y){
	x *= x;
	y *= y;
	double r = x + y;
	if (r <= 9)
		return 100;
	else if (r > 9 && r <= 36)
		return 80;
	else if (r > 36 && r <= 81)
		return 60;
	else if (r > 81 && r <= 144)
		return 40;
	else if (r > 144 && r <= 225)
		return 20;
	else
		return 0;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		double x1, y1;
		int score_1 = 0;
		int score_2 = 0;
		for (int i = 0; i < 3; i++){
			cin >> x1;
			cin >> y1;
			score_1 += get_score(x1, y1);
		}
		for (int i = 0; i < 3; i++){
			cin >> x1;
			cin >> y1;
			score_2 += get_score(x1, y1);
		}
		printf("SCORE: %d to %d, ", score_1 , score_2);
		if (score_1 == score_2)
			printf("TIE.\n");
		else if (score_1 > score_2)
			printf("PLAYER 1 WINS.\n");
		else
			printf("PLAYER 2 WINS.\n");
	}
}