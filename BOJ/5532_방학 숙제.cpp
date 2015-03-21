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
	int L, A, B, C, D;
	vector<int> data;
	cin >> L >> A >> B >> C >> D;
	if (A % C == 0)
		A = A / C;
	else
		A = (A / C) + 1;
	if (B % D == 0)
		B = B / D;
	else
		B = (B / D) + 1;
	cout << L - max(A, B) << endl;
}