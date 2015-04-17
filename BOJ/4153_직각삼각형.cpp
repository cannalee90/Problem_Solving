#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int n, m;

int main()
{
#ifdef _CONSOLE
	freopen("\input.txt", "r", stdin);
#endif
	int side[3];
	while (cin >> side[0] >> side[1] >> side[2]){
		if (side[0] == 0 && side[1] == 0 && side[2] == 0) 
			break;
		else{
			sort(side, side + 3);
			if (pow(side[0], 2) + pow(side[1], 2) == pow(side[2], 2))
				cout << "right" << endl;
			else
				cout << "wrong" << endl;
		}
	}
}