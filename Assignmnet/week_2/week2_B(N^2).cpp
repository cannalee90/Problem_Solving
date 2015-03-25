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

int n;

class Line{
public:
	double X;
	double Yb;
	double Ye;
	bool type;
	Line(double X, double Yb, double Ye, bool type){
		this->X = X;
		this->Yb = Yb;
		this->Ye = Ye;
		this->type = type;
	}
	bool operator <(const Line &a) const
	{
		return X < a.X;
	}
};


vector<Line> L;
vector<double> y_coordinate;
vector<int> cnt;

double get_height(){
	double height = 0;
	for (int i = 0; i < y_coordinate.size() - 1; i++){
		if (cnt[i]){
			height += y_coordinate[i + 1] - y_coordinate[i];
		}
	}
	return height;
}

void isIn(double &Yb, double &Ye, bool type){
	bool flag = false;
	for (int i = 0; i < y_coordinate.size() - 1; i++){
		if (y_coordinate[i] >= Yb && y_coordinate[i + 1] <= Ye){
			if (type)
				cnt[i]++;
			else
				cnt[i]--;
		}
	}
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	double ans = 0;
	int n;
	scanf("%d", &n);
	cnt.resize(n * 2 + 1, 0);

	for (int i = 0; i < n; i++){
		double xb, xe, yb, ye;
		scanf("%lf %lf %lf %lf", &xb, &yb, &xe, &ye);
		xe += xb;
		ye += yb;
		L.push_back(Line(xb, yb, ye, true));
		L.push_back(Line(xe, yb, ye, false));
		y_coordinate.push_back(yb);
		y_coordinate.push_back(ye);
	}

	sort(L.begin(), L.end());
	sort(y_coordinate.begin(), y_coordinate.end());
	for (int i = 0; i < L.size() - 1; i++){
		Line here = L[i];
		double difference = L[i + 1].X - L[i].X;
		isIn(here.Yb, here.Ye, here.type);
		ans += get_height() * difference;
	}
	printf("%d\n", (int)ans);
}