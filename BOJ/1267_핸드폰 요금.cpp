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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int cost_m = 0;
	int cost_y = 0;
	cin >> n;
	vector<int> data(n + 1);
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	for (int i = 0; i < n; i++){
		int time = data[i];
		while (time >= 0){
			cost_m += 15;
			time -= 60;
		}
		time = data[i];
		while (time >= 0){
			cost_y += 10;
			time -= 30;
		}
	}
	if (cost_y < cost_m)
		printf("Y %d\n", cost_y);
	else if (cost_y > cost_m)
		printf("M %d\n", cost_m);
	else
		printf("Y M %d\n", cost_m);

}
