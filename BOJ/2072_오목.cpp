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

vector<vector<int > > baduk(25, vector<int>(25, -1));

bool isPossible(int compare_height, int compare_width, int color){
	if (compare_height < 1 || compare_width < 1 || compare_height > 19 || compare_width > 19) return 0;
	if (baduk[compare_height][compare_width] != color) return 0;
	return 1;
}


bool is_win(int height, int width){
	int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, -1 } };
	for (int i = 0; i < 4; i++)	{
		int cnt = 0;
		for (int j = 1; j < 19; j++){
			int compare_height = height + (mmove[i][0] * j);
			int compare_width = width + (mmove[i][1] * j);	
			if (isPossible(compare_height, compare_width, baduk[height][width])){
				cnt++;
			}else{
				break;
			}
		}
		for (int j = 1; j < 19; j++){
			int compare_height = height - (mmove[i][0] * j);
			int compare_width = width - (mmove[i][1] * j);
			if (isPossible(compare_height, compare_width, baduk[height][width])){
				cnt++;
			}else {
				break;
			}
		}
		if (cnt == 4){
			return true;
		}
	}
	return false;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int height;
		int width;
		cin >> height >> width;
		baduk[height][width] = i % 2;
		if (is_win(height, width)){
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}
