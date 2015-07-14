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



int main(){

#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		int bx, by, ex, ey;
		cin >> bx >> by >> ex >> ey;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++){
			bool inA = false, inB = false;
			int X, Y, R;
			cin >> X >> Y >> R;
			int x = (X - bx) * (X - bx);
			int y = (Y - by) * (Y - by);
			if (R * R > x + y ) inA = true;
			x = (X - ex) * (X - ex);
			y = (Y - ey) * (Y - ey);
			if (R * R > x  + y ) inB = true;
			if ((inA == true || inB == true) && (inA != inB))
				ans++;
		}
		cout << ans << endl;
	}
}