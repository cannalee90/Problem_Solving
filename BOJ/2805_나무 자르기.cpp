#include <iostream>
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

long long n, sum;
long long max_height = INT_MIN;
long long min_total = INT_MAX;
vector<long long> number;
long long cnt;

long long get_difference(long long pivot)
{
	long long difference = 0;
	for (long long i = 0; i < n; i++)
	{
		if(number[i] > pivot)
		difference += number[i] - pivot;
	}
	return difference;
}

void binary_search(long long left, long long right)
{
	long long	 pivot = (left + right) / 2;
	long long total = get_difference(pivot);
	if (total >= sum && pivot > max_height)
	{
		max_height = pivot;
		min_total = total;
	}
	if (right == pivot || left == right) return;
	if (total >= sum)
	{
		binary_search(pivot + 1, right);
	}
	if (total < sum)
	{
		binary_search(left, pivot - 1);
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	long long mmax = INT_MIN;
	cin >> n >> sum;
	for (long long i = 0; i < n; i++)
	{
		long long t1;
		cin >> t1;
		number.push_back(t1);
		mmax = max(mmax, t1);
	}
	binary_search(0, mmax-1);
	cout << max_height << endl;
}