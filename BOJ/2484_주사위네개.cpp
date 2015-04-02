#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	int mmax = -1;
	cin >> n;
	while (n--){
		int score = 0;
		vector<int> dice(4);
		for (int i = 0; i < 4; i++)
			cin >> dice[i];
		sort(dice.begin(), dice.end());
		if (dice[0] == dice[3])
			score = 50000 + (5000 * dice[0]);
		else if (dice[0] == dice[2] || dice[1] == dice[3])
			score = 10000 + dice[2] * 1000;
		else if (dice[0] != dice[1] && dice[1] != dice[2] && dice[2] != dice[3])
			score = dice[3] * 100;
		else if (dice[0] == dice[1] && dice[2] == dice[3])
			score = 2000 + dice[0] * 500 + dice[2] * 500;
		else if (dice[0] == dice[1])
			score = 1000 + dice[0] * 100;
		else
			score =  1000 + dice[2] * 100;
		if (mmax < score)
			mmax = score;
	}

}
