#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 900000000


typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if(r1 > r2) swap(r1, r2);
		int differ_x = abs(x1 - x2);
		int differ_y = abs(y1 - y2);
		int D = (differ_x) + (differ_y);
		if(D == r1 + r2 || D == r2 - r1 && D != 0) cout << "1" << endl;
		else if(r2 - r1 < D && D < r2 + r1) cout << "2" << endl;
		else if(D == 0 && r1 == r2) cout << "-1" << endl;
		else cout << "0" << endl;
	}
}