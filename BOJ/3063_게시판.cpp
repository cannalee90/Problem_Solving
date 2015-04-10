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

class squre{
public:
	int x1;
	int y1;
	int x2; 
	int y2;
	squre(int x1, int y1, int x2, int y2){
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;

	}
};


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		int n = 4;
		ll ans = 0;
		vector<int> x, y;
		vector<squre> S;
		for (int i = 0; i < 2; i++){
			int tx1, ty1, tx2, ty2;
			cin >> tx1 >> ty1 >> tx2 >> ty2;
			x.push_back(tx1);
			y.push_back(ty1);
			x.push_back(tx2);
			y.push_back(ty2);
			S.push_back(squre(tx1, ty1, tx2, ty2));
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		for (int i = 0; i < n - 1; i++){
			for (int j = 0; j < n - 1; j++){
				int x1 = x[i];
				int x2 = x[i + 1];
				int y1 = y[j];
				int y2 = y[j + 1];

				if (S[0].x1 <= x1 && x2 <= S[0].x2 && S[0].y1 <= y1 && y2 <= S[0].y2){
					if (S[1].x1 <= x1 && x2 <= S[1].x2 && S[1].y1 <= y1 && y2 <= S[1].y2) continue;
						ans += (x2 - x1) * (y2 - y1);
				}
			}
		}
		cout << ans << endl;
	}
}