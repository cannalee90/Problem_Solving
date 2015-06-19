#include <iostream>
#include <climits>
#include <functional>
#include <utility>
#include <limits.h>
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

int m, t;
double n;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	double a;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		printf("%.10lf\n", a / (double)6);
	}
}
