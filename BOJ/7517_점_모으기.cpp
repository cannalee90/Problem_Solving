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

int n, m;

int mmove[9][2] = { { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, -1 }, { 0, 0 },{ 0, 1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> m >> n;
	vector<int> vx(n);
	vector<int> vy(n);
	int x_ave, y_ave;
	int x_total = 0, y_total = 0;
	for (int i = 0; i < n; i++) 
		cin >> vx[i] >> vy[i];
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	if (n % 2 == 1){
		x_ave = vx[n / 2];
		y_ave = vy[n / 2];
	}
	else{
		x_ave = (vx[n / 2] + vx[(n / 2) - 1]) / 2;
		y_ave = (vy[n / 2] + vy[(n / 2) - 2]) / 2;
	}
	int ans =INT_MAX;
		for (int k = 0; k < 9; k++){
			int temp = 0;

			for (int i = 0; i < n; i++){
				
				temp += abs((x_ave + mmove[k][0]) - vx[i]);
				temp += abs((y_ave + mmove[k][1]) - vy[i]);
			}
			ans = min(temp, ans);

		}
	cout << ans << endl;
}