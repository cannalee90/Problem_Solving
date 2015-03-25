#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

class rect{
public:
	double x1;
	double x2;
	double y1;
	double y2;
	rect(double x1, double y1, double x2, double y2){
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
	}
};

vector<double> x_coordinate;
vector<double> y_coordinate;
vector<rect> rec;

int n;


bool isIn(double x1, double y1, double x2, double y2){
	for (int k = 0; k < n; k++){
		double rect_x1 = rec[k].x1;
		double rect_x2 = rec[k].x2;
		double rect_y1 = rec[k].y1;
		double rect_y2 = rec[k].y2;
		if (rect_x1 <= x1 && rect_y1 <= y1 && rect_x2 >= x2 && rect_y2 >= y2)
			return 1;
	}
	return 0;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);

#endif
	double ans = 0;
	const double setting = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		double t1, t2, t3, t4;
		scanf("%lf %lf %lf %lf", &t1, &t2, &t3, &t4);
		t1 *= setting, t2 *= setting, t3 *= setting, t4 *= setting;

		x_coordinate.push_back(t1);
		x_coordinate.push_back(t1 + t3);
		y_coordinate.push_back(t2);
		y_coordinate.push_back(t2 + t4);
		rec.push_back(rect(t1, t2, t1 + t3, t2 + t4));
	}

	sort(x_coordinate.begin(), x_coordinate.end());
	sort(y_coordinate.begin(), y_coordinate.end());
	int cnt = 0;
	for (int i = 0; i < n * 2- 1; i++){
		for (int j = 0; j < n * 2- 1; j++){

			double x1 = x_coordinate[i];
			double x2 = x_coordinate[i + 1];
			double y1 = y_coordinate[j];
			double y2 = y_coordinate[j + 1];

			if (isIn(x1, y1, x2, y2) && y2 - y1 != (double)0 && x2 - x1 != (double)0){
				ans += (double)(x2 - x1) * (double)(y2 - y1);
			}
		}
	}
	printf("%d\n", (int)ans);
}