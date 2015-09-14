#include <iostream>
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

const int M = 100010;
int n, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int data[2][10];
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 10; j++){
			cin >> data[i][j];
		}
	}
	int a = 0, b = 0;
	for (int i = 0; i < 10; i++){
		if (data[0][i] > data[1][i]) a++;
		else if (data[0][i] < data[1][i]) b++;
	}
	if (a > b) cout << "A" << endl;
	else if (b > a) cout << "B" << endl;
	else cout << "D" << endl;
}