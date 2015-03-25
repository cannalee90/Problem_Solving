	#include <iostream>
	#include <limits.h>
	#include <math.h>	
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
	#define _USE_MATH_DEFINES
	
	int main(){
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
	#endif
		double r;
		cin >> r;
		printf("%.6lf\n", r * r * 3.14159265358979323846);
		printf("%.6lf\n", ((r * 2) * (r * 2)) / 2);

	}