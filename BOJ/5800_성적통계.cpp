#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include<limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	for(int k = 0; k<t; k++){
		int n;
		int mmax = INT_MIN;
		int mmin = INT_MAX;
		vector<int> data;
		cin >> n;
		for (int i = 0; i < n; i++)	{
			int t1;
			cin >> t1;
			mmax = max(mmax, t1);
			mmin = min(mmin, t1);
			data.push_back(t1);
		}
		sort(data.begin(), data.end());
		int largest_gap = INT_MIN;
		for (int i = 0; i < data.size() - 1; i++)
		{
			largest_gap = max(largest_gap, data[i + 1] - data[i]);
		}
		printf("Class %d\n", k + 1);
		printf("Max %d, Min %d, Largest gap %d\n", mmax, mmin, largest_gap);
		
	}
}
